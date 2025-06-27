#include "joystick.h"
#include "main.h"
#include "usb_device.h"

extern USBD_HandleTypeDef hUsbDeviceFS;

extern uint16_t adcValues[4];
extern uint16_t center1_x, center1_y, center2_x, center2_y;

#define DEAD_ZONE 100

void Send_Joystick_Report(void) {
    JoystickReport report;

    // Normalize joystick 1
    int16_t dx1 = (int16_t)adcValues[2] - center1_x;
    int16_t dy1 = (int16_t)adcValues[3] - center1_y;

    // Normalize joystick 2
    int16_t dx2 = (int16_t)adcValues[0] - center2_x;
    int16_t dy2 = (int16_t)adcValues[1] - center2_y;

    // Apply dead zone and scale to int8_t (-128 to +127)
    report.joy1_x = (abs(dx1) > DEAD_ZONE) ? dx1 / 32 : 0;
    report.joy1_y = (abs(dy1) > DEAD_ZONE) ? dy1 / 32 : 0;
    report.joy2_x = (abs(dx2) > DEAD_ZONE) ? dx2 / 32 : 0;
    report.joy2_y = (abs(dy2) > DEAD_ZONE) ? dy2 / 32 : 0;

    // Read buttons (7 total from PB2 to PB8)
    report.buttons = 0;
    report.buttons |= (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2) == GPIO_PIN_RESET) << 0;
    report.buttons |= (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3) == GPIO_PIN_RESET) << 1;
    report.buttons |= (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4) == GPIO_PIN_RESET) << 2;
    report.buttons |= (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5) == GPIO_PIN_RESET) << 3;
    report.buttons |= (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6) == GPIO_PIN_RESET) << 4;
    report.buttons |= (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) == GPIO_PIN_RESET) << 5;
    report.buttons |= (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8) == GPIO_PIN_RESET) << 6;

    // Send USB HID report (must match report descriptor size!)
    USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&report, sizeof(report));
}
