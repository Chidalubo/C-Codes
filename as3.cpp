#include <cstdint>
#include <gtest/gtest.h>

// Define a class to manage the header fields
class PacketHeader {
public:
    // Constructor
    PacketHeader(uint8_t type, bool T, uint8_t window, uint16_t seqNum, uint16_t length, uint32_t CRC1)
        : type_(type), T_(T), window_(window), seqNum_(seqNum), length_(length), CRC1_(CRC1) {}

    // Setter functions
    void setType(uint8_t type) { type_ = type; }
    void setT(bool T) { T_ = T; }
    void setWindow(uint8_t window) { window_ = window; }
    void setSeqNum(uint16_t seqNum) { seqNum_ = seqNum; }
    void setLength(uint16_t length) { length_ = length; }
    void setCRC1(uint32_t CRC1) { CRC1_ = CRC1; }

    // Getter functions
    uint8_t getType() const { return type_; }
    bool getT() const { return T_; }
    uint8_t getWindow() const { return window_; }
    uint16_t getSeqNum() const { return seqNum_; }
    uint16_t getLength() const { return length_; }
    uint32_t getCRC1() const { return CRC1_; }

private:
    uint8_t type_;
    bool T_;
    uint8_t window_;
    uint16_t seqNum_;
    uint16_t length_;
    uint32_t CRC1_;
};

// Google Test
TEST(PacketHeaderTest, SettersAndGetters) {
    PacketHeader header(1, true, 2, 3, 7, 12345);

    EXPECT_EQ(header.getType(), 1);
    EXPECT_EQ(header.getT(), true);
    EXPECT_EQ(header.getWindow(), 2);
    EXPECT_EQ(header.getSeqNum(), 3);
    EXPECT_EQ(header.getLength(), 7);
    EXPECT_EQ(header.getCRC1(), 12345);

    header.setType(4);
    header.setT(false);
    header.setWindow(5);
    header.setSeqNum(6);
    header.setLength(8);
    header.setCRC1(54321);

    EXPECT_EQ(header.getType(), 4);
    EXPECT_EQ(header.getT(), false);
    EXPECT_EQ(header.getWindow(), 5);
    EXPECT_EQ(header.getSeqNum(), 6);
    EXPECT_EQ(header.getLength(), 8);
    EXPECT_EQ(header.getCRC1(), 54321);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
