#include "7seg_com_anode.hpp"

// Bảng mã LED cho Common Anode: A, B, C, D, E, F, G
const uint8_t SevenSegmentCommonAnode::segmentMap[10] = {
    0b00111111, // 0: A, B, C, D, E, F
    0b00000110, // 1: B, C
    0b01011011, // 2: A, B, D, E, G
    0b01001111, // 3: A, B, C, D, G
    0b01100110, // 4: B, C, F, G
    0b01101101, // 5: A, C, D, F, G
    0b01111101, // 6: A, C, D, E, F, G
    0b00000111, // 7: A, B, C
    0b01111111, // 8: A, B, C, D, E, F, G
    0b01101111  // 9: A, B, C, D, F, G
};

// Constructor
SevenSegmentCommonAnode::SevenSegmentCommonAnode(GPIO_TypeDef *gpioPort,
                                                 uint16_t pinA, uint16_t pinB, uint16_t pinC,
                                                 uint16_t pinD, uint16_t pinE, uint16_t pinF, uint16_t pinG)
    : port(gpioPort), pins{pinA, pinB, pinC, pinD, pinE, pinF, pinG} {
    // Tắt tất cả các đoạn LED khi khởi tạo
    for (int i = 0; i < 7; i++) {
        HAL_GPIO_WritePin(port, pins[i], GPIO_PIN_RESET);
    }
}

// Hàm viết dữ liệu tới các chân GPIO điều khiển LED
void SevenSegmentCommonAnode::writeSegments(uint8_t value) {
    for (int i = 0; i < 7; i++) {
        // Dùng logic thấp (0) để bật các đoạn LED trong kiểu Common Anode
        HAL_GPIO_WritePin(port, pins[i], (value & (1 << (6 - i))) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    }
}

// Hàm hiển thị số từ 0 đến 9
void SevenSegmentCommonAnode::displayNumber(uint8_t number) {
    if (number < 10) {
        writeSegments(segmentMap[number]);
    }
}
