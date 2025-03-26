#include <iostream>
#include <fstream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 512
#define WINDOW_SIZE 5

class SlidingWindow {
public:
    SlidingWindow(int windowSize) : windowSize(windowSize), base(0), nextSeqNum(0) {
        ackReceived.resize(windowSize, false);
    }

    bool isFull() const {
        return nextSeqNum == base + windowSize;
    }

    void advanceBase() {
        base++;
        ackReceived.pop_front();
        ackReceived.push_back(false);
    }

    void markAckReceived(int seqNum) {
        int index = seqNum - base;
        if (index >= 0 && index < windowSize) {
            ackReceived[index] = true;
        }
    }

    bool isAckReceived(int seqNum) const {
        int index = seqNum - base;
        return index >= 0 && index < windowSize && ackReceived[index];
    }

    int getNextSeqNum() const {
        return nextSeqNum;
    }

    void advanceSeqNum() {
        nextSeqNum++;
    }

private:
    int windowSize;
    int base;
    int nextSeqNum;
    std::deque<bool> ackReceived;
};

class BufferManager {
public:
    BufferManager(std::ifstream &file) : file(file), fileOffset(0) {}

    ssize_t readData(char *buffer, size_t bufferSize) {
        file.read(buffer, bufferSize);
        return file.gcount();
    }

    bool hasMoreData() const {
        return !file.eof();
    }

private:
    std::ifstream &file;
    std::streampos fileOffset;
};

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 4 || argc > 6) {
        std::cerr << "Usage: " << argv[0] << " [-f data_file] host port\n";
        return 1;
    }

    const char *host = argv[argc - 3];
    const int port = std::stoi(argv[argc - 2]);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Set up server address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        error("ERROR invalid host address");
    }

    // Read data from file
    std::ifstream file;
    if (argc == 6 && std::string(argv[1]) == "-f") {
        file.open(argv[2], std::ios::binary);
        if (!file.is_open()) {
            error("ERROR opening file");
        }
    }

    // Send data using sliding window
    char buffer[MAX_BUFFER_SIZE];
    SlidingWindow slidingWindow(WINDOW_SIZE);
    BufferManager bufferManager(file);

    while (slidingWindow.isFull() || bufferManager.hasMoreData()) {
        if (!slidingWindow.isFull() && bufferManager.hasMoreData()) {
            ssize_t bytesRead = bufferManager.readData(buffer, MAX_BUFFER_SIZE);
            ssize_t bytesSent = sendto(sockfd, buffer, bytesRead, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
            if (bytesSent < 0) {
                error("ERROR sending data");
            }
            slidingWindow.advanceSeqNum();
        }

        // Receive acknowledgments
        char ackBuffer[sizeof(int)];
        ssize_t ackSize = recv(sockfd, ackBuffer, sizeof(int), MSG_DONTWAIT);
        if (ackSize > 0) {
            int ackNum;
            memcpy(&ackNum, ackBuffer, sizeof(int));
            slidingWindow.markAckReceived(ackNum);
            while (slidingWindow.isAckReceived(slidingWindow.getNextSeqNum())) {
                slidingWindow.advanceBase();
            }
        }
    }

    // Close file and socket
    file.close();
    close(sockfd);

    std::cout << "File sent successfully\n";

    return 0;
}
