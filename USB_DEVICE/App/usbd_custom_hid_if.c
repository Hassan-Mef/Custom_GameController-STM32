/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : usbd_custom_hid_if.c
  * @version        : v1.0_Cube
  * @brief          : USB Device Custom HID interface file.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "usbd_custom_hid_if.h"

/* USER CODE BEGIN INCLUDE */

/* USER CODE END INCLUDE */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/** @addtogroup STM32_USB_OTG_DEVICE_LIBRARY
  * @brief Usb device.
  * @{
  */

/** @addtogroup USBD_CUSTOM_HID
  * @{
  */

/** @defgroup USBD_CUSTOM_HID_Private_TypesDefinitions USBD_CUSTOM_HID_Private_TypesDefinitions
  * @brief Private types.
  * @{
  */

/* USER CODE BEGIN PRIVATE_TYPES */
__ALIGN_BEGIN static uint8_t CustomHID_Buffer[USBD_CUSTOM_HID_REPORT_DESC_SIZE] __ALIGN_END;
/* USER CODE END PRIVATE_TYPES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Defines USBD_CUSTOM_HID_Private_Defines
  * @brief Private defines.
  * @{
  */

/* USER CODE BEGIN PRIVATE_DEFINES */

/* USER CODE END PRIVATE_DEFINES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Macros USBD_CUSTOM_HID_Private_Macros
  * @brief Private macros.
  * @{
  */

/* USER CODE BEGIN PRIVATE_MACRO */

/* USER CODE END PRIVATE_MACRO */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Variables USBD_CUSTOM_HID_Private_Variables
  * @brief Private variables.
  * @{
  */

/** Usb HID report descriptor. */
__ALIGN_BEGIN static uint8_t CUSTOM_HID_ReportDesc_FS[USBD_CUSTOM_HID_REPORT_DESC_SIZE] __ALIGN_END =
{
  /* USER CODE BEGIN 0 */
		 0x05, 0x01,        // Usage Page (Generic Desktop)
		    0x09, 0x05,        // Usage (Game Pad)
		    0xA1, 0x01,        // Collection (Application)

		    // Buttons (16 buttons)
		    0x05, 0x09,        //   Usage Page (Button)
		    0x19, 0x01,        //   Usage Minimum (Button 1)
		    0x29, 0x10,        //   Usage Maximum (Button 16)
		    0x15, 0x00,        //   Logical Minimum (0)
		    0x25, 0x01,        //   Logical Maximum (1)
		    0x75, 0x01,        //   Report Size (1)
		    0x95, 0x10,        //   Report Count (16)
		    0x81, 0x02,        //   Input (Data, Variable, Absolute)

		    // 2 Analog Joysticks: X, Y, Rx, Ry
		    0x05, 0x01,        //   Usage Page (Generic Desktop)
		    0x09, 0x30,        //   Usage (X)
		    0x09, 0x31,        //   Usage (Y)
		    0x09, 0x33,        //   Usage (Rx)
		    0x09, 0x34,        //   Usage (Ry)
		    0x15, 0x00,        //   Logical Minimum (0)
		    0x26, 0xFF, 0x00,  //   Logical Maximum (255)
		    0x75, 0x08,        //   Report Size (8)
		    0x95, 0x04,        //   Report Count (4)
		    0x81, 0x02,        //   Input (Data, Variable, Absolute)

		    // Triggers: Z, Rz
		    0x09, 0x32,        //   Usage (Z)
		    0x09, 0x35,        //   Usage (Rz)
		    0x75, 0x08,        //   Repor-t Size (8)
		    0x95, 0x02,        //   Report Count (2)
		    0x81, 0x02,        //   Input (Data, Variable, Absolute)
  /* USER CODE END 0 */
  0xC0    /*     END_COLLECTION	             */
};

/* USER CODE BEGIN PRIVATE_VARIABLES */

/* USER CODE END PRIVATE_VARIABLES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Exported_Variables USBD_CUSTOM_HID_Exported_Variables
  * @brief Public variables.
  * @{
  */
extern USBD_HandleTypeDef hUsbDeviceFS;

/* USER CODE BEGIN EXPORTED_VARIABLES */

/* USER CODE END EXPORTED_VARIABLES */
/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_FunctionPrototypes USBD_CUSTOM_HID_Private_FunctionPrototypes
  * @brief Private functions declaration.
  * @{
  */

static int8_t CUSTOM_HID_Init_FS(void);
static int8_t CUSTOM_HID_DeInit_FS(void);
static int8_t CUSTOM_HID_OutEvent_FS(uint8_t event_idx, uint8_t state);

/**
  * @}
  */

USBD_CUSTOM_HID_ItfTypeDef USBD_CustomHID_fops_FS =
{
  CUSTOM_HID_ReportDesc_FS,
  CUSTOM_HID_Init_FS,
  CUSTOM_HID_DeInit_FS,
  CUSTOM_HID_OutEvent_FS
};

/** @defgroup USBD_CUSTOM_HID_Private_Functions USBD_CUSTOM_HID_Private_Functions
  * @brief Private functions.
  * @{
  */

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Initializes the CUSTOM HID media low layer
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_Init_FS(void)
{
  /* USER CODE BEGIN 4 */
  return (USBD_OK);
  /* USER CODE END 4 */
}

/**
  * @brief  DeInitializes the CUSTOM HID media low layer
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_DeInit_FS(void)
{
  /* USER CODE BEGIN 5 */
  return (USBD_OK);
  /* USER CODE END 5 */
}

/**
  * @brief  Manage the CUSTOM HID class events
  * @param  event_idx: Event index
  * @param  state: Event state
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_OutEvent_FS(uint8_t event_idx, uint8_t state)
{
  /* USER CODE BEGIN 6 */
  UNUSED(event_idx);
  UNUSED(state);

  /* Start next USB packet transfer once data processing is completed */
  if (USBD_CUSTOM_HID_ReceivePacket(&hUsbDeviceFS) != (uint8_t)USBD_OK)
  {
    return -1;
  }

  return (USBD_OK);
  /* USER CODE END 6 */
}

/* USER CODE BEGIN 7 */
/**
  * @brief  Send the report to the Host
  * @param  report: The report to be sent
  * @param  len: The report length
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
/*
static int8_t USBD_CUSTOM_HID_SendReport_FS(uint8_t *report, uint16_t len)
{
  return USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, report, len);
}
*/
//
//void Send_CustomHID_Report(uint8_t* report, uint16_t len) {
//    USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, report, len);
//}

#define DEAD_ZONE 200

uint16_t apply_deadzone(uint16_t raw) {
    if (raw > 2048 - DEAD_ZONE && raw < 2048 + DEAD_ZONE)
        return 2048;
    return raw;
}

uint8_t adc_to_hid_u8(uint16_t raw) {
    int32_t val = raw - 2048;
    val = (val * 127) / 2048;

    if (val > 127) val = 127;
    if (val < -128) val = -128;

    return (uint8_t)(val + 128);  // Shift to 0–255 range
}



USBD_StatusTypeDef CUSTOM_HID_SendReport_FS(uint8_t *reportPtr)
{
  return USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, reportPtr, 8);
}

/**
  * @brief  Build joystick report in CustomHID_Buffer, then send it
  */
void Joystick_SendReport(void)
{
    uint16_t buttons = 0;

    // Active-low buttons on PB2–PB9
    if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2) == GPIO_PIN_RESET) buttons |= 1 << 2; // A  // 2 y
    if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3) == GPIO_PIN_RESET) buttons |= 1 << 3; // B  // 3 x
    if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4) == GPIO_PIN_RESET) buttons |= 1 << 0; // X  // 0 A
    if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5) == GPIO_PIN_RESET) buttons |= 1 << 1; // Y  //1  B

    if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_RESET) buttons |= 1 << 9; //    // button 9 is option button



//	if (optionButtonPressed) {
//		buttons |= 1 << 9; // Choose an unused bit for the Option button
//	    optionButtonPressed = 0; // Reset after sending
//	}



    if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8) == GPIO_PIN_RESET) buttons |= 1 << 14; // D-Left
    if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9) == GPIO_PIN_RESET) buttons |= 1 << 15; // D-Right

    if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6) == GPIO_PIN_RESET) buttons |= 1 << 12; // D-Up
    if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) == GPIO_PIN_RESET) buttons |= 1 << 13; // D-Down

    CustomHID_Buffer[0] = buttons & 0xFF;
    CustomHID_Buffer[1] = (buttons >> 8) & 0xFF;

    extern uint16_t adcValues[6]; // assuming [0]=X1, [1]=Y1, [2]=X2, [3]=Y2, [4]=Z, [5]=Rz

    uint8_t joystick_axes[6];
    for (int i = 0; i < 6; i++) {
        joystick_axes[i] = adc_to_hid_u8(apply_deadzone(adcValues[i]));
    }


    CustomHID_Buffer[2] = joystick_axes[0]; // X
    CustomHID_Buffer[3] = joystick_axes[1]; // Y
    CustomHID_Buffer[4] = joystick_axes[2]; // Rx
    CustomHID_Buffer[5] = joystick_axes[3]; // Ry
//    CustomHID_Buffer[6] = joystick_axes[4]; // Z
//    CustomHID_Buffer[7] = joystick_axes[5]; // Rz


    // Send 8-byte report to host
    CUSTOM_HID_SendReport_FS(CustomHID_Buffer);
}


/* USER CODE END 7 */

/* USER CODE BEGIN PRIVATE_FUNCTIONS_IMPLEMENTATION */

/* USER CODE END PRIVATE_FUNCTIONS_IMPLEMENTATION */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

