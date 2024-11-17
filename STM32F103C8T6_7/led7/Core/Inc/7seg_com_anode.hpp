/*
 * 7seg_com_anode.hpp
 *
 *  Created on: Nov 17, 2024
 *      Author: datzi
 */

#ifndef INC_7SEG_COM_ANODE_HPP_
#define INC_7SEG_COM_ANODE_HPP_

#include "main.h"

class SevenSegmentCommonAnode {
private:
    GPIO_TypeDef *port;     // Cổng GPIO
    uint16_t pins[7];       // Các chân GPIO tương ứng A, B, C, D, E, F, G

    // Bảng mã cho các số từ 0-9
    static const uint8_t segmentMap[10];

    // Bật/tắt các đoạn
    void writeSegments(uint8_t value);

public:
    // Constructor
    SevenSegmentCommonAnode(GPIO_TypeDef *gpioPort, uint16_t pinA, uint16_t pinB, uint16_t pinC,
                            uint16_t pinD, uint16_t pinE, uint16_t pinF, uint16_t pinG);

    // Hiển thị số từ 0-9
    void displayNumber(uint8_t number);
};



#endif /* INC_7SEG_COM_ANODE_HPP_ */
