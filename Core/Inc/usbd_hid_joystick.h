/*
 * usbd_hid_joystick.h
 *
 *  Created on: May 18, 2025
 *      Author: hassa
 */

#ifndef INC_USBD_HID_JOYSTICK_H_
#define INC_USBD_HID_JOYSTICK_H_


#include "usbd_hid.h"

#pragma pack(push, 1)
typedef struct {
    uint8_t buttons;       // 8 buttons (1 bit each)
    uint8_t padding;       // Padding to align to byte boundary

    uint16_t joy1_x;       // Joystick 1 X axis
    uint16_t joy1_y;       // Joystick 1 Y axis

    uint16_t joy2_x;       // Joystick 2 X axis
    uint16_t joy2_y;       // Joystick 2 Y axis
} HID_JoystickReport_Data_t;
#pragma pack(pop)
#endif /* INC_USBD_HID_JOYSTICK_H_ */
