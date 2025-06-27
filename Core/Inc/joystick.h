/*
 * joystick.h
 *
 *  Created on: May 18, 2025
 *      Author: hassa
 */

#ifndef __JOYSTICK_H
#define __JOYSTICK_H

#include "usbd_customhid.h"

typedef struct {
    int8_t joy1_x;
    int8_t joy1_y;
    int8_t joy2_x;
    int8_t joy2_y;
    uint8_t buttons; // 7 buttons packed in 1 byte (bit 0-6)
} __attribute__((packed)) JoystickReport;

void Send_Joystick_Report(void);

#endif

