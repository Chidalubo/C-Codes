#include <iostream>
#include <fstream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 512

class BufferManager {
public:
    BufferManager(std::ofstream &file) : file(file) {}

    void writeData(const char *buffer, size_t bufferSize) {
        file.write(buffer, bufferSize);
    }

private:
    std::ofstream &file;
};

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 4 || argc > 6) {
        std::cerr << "Usage: " << argv[0] << " [-f data_file] [-6] port\n";
        return 1;
    }

    int port = std::stoi(argv[argc - 1]);

    // Create socket
    int sockfd;
    if (argc == 5 && std::string(argv[1]) == "-6") {
        sockfd = socket(AF_INET6, SOCK_DGRAM, 0);
    } else {
        sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    }

    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Set up server address structure
    struct sockaddr_in6 server_addr6;
    struct sockaddr_in server_addr;

    if (argc == 5 && std::string(argv[1]) == "-6") {
        memset(&server_addr6, 0, sizeof(server_addr6));
        server_addr6.sin6_family = AF_INET6;
        server_addr6.sin6_port = htons(port);
        server_addr6.sin6_addr = in6addr_any;
    } else {
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = INADDR_ANY;
    }

    // Bind the socket
    if (bind(sockfd, (struct sockaddr *)(&server_addr6), sizeof(server_addr6)) < 0 && bind(sockfd, (struct sockaddr *)(&server_addr), sizeof(server_addr)) < 0) {
        error("ERROR on binding");
    }

    // Open file for writing
    std::ofstream file;
    if (argc == 4 && std::string(argv[2]) == "-f") {
        file.open(argv[3], std::ios::binary);
        if (!file.is_open()) {
            error("ERROR opening file for writing");
        }
    }

    // Receive data using sliding window
    char buffer[MAX_BUFFER_SIZE];
    int expectedSeqNum = 0;

    while (true) {
        char ackBuffer[sizeof(int)];
        ssize_t bytesRead = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
        if (bytesRead < 0) {
            error("ERROR receiving data");
        } else if (bytesRead == 0) {
            break;  // End of transmission
        }

        // Simulate different processing speeds
        usleep(5000);  // Sleep for 5 milliseconds to simulate slower processing

        if (expectedSeqNum == buffer[0]) {
            // In-order packet received
            file.write(buffer + 1, bytesRead - 1);  // Write data to file
            expectedSeqNum++;
        }

        // Send acknowledgment
        memcpy(ackBuffer, &expectedSeqNum, sizeof(int));
        ssize_t ackSize = sendto(sockfd, ackBuffer, sizeof(int), 0, NULL, 0);
        if (ackSize < 0) {
            error("ERROR sending acknowledgment");
        }
    }

    // Close file and socket
    file.close();
    close(sockfd);

    std::cout << "File received successfully\n";

    return 0;
}
