# 🕹️ STM32F411 USB Game Controller

[![Platform](https://img.shields.io/badge/platform-STM32F411CEU6-blue)](https://www.st.com/en/microcontrollers-microprocessors/stm32f411ce.html)
[![USB HID](https://img.shields.io/badge/interface-USB%20HID-green)]()
[![License](https://img.shields.io/badge/license-MIT-lightgrey)]()

> A fully custom USB game controller built using the STM32F411CEU6 microcontroller. Features 9 buttons, 2 analog joysticks, DMA ADC sampling, and a modified Xbox 360 HID descriptor.

---

## 📸 Final Product


![Final Product](final.jpg)

---

## 📦 Clone and Build Instructions

```bash
# Clone the repository
git clone https://github.com/yourusername/stm32-usb-gamepad.git
cd stm32-usb-gamepad

# Open in STM32CubeIDE or import as existing project
# Flash to your STM32F411 using ST-Link or DFU
```

Full documentation continues below...

---

# STM32F411CEU6 USB Game Controller

A **custom USB game controller** built using the STM32F411CEU6 (Black Pill) microcontroller. This controller features **9 buttons**, **2 analog joysticks**, and communicates with a PC via **USB HID** using a modified Xbox 360-style HID report descriptor. It also uses **ADC in circular DMA mode**, **deadzone processing**, and **timer-triggered sampling**.

---

## 🔧 Features
- ✅ 9 Buttons (including Option button)
- ✅ 2 Analog Joysticks (X/Y and Rx/Ry)
- ✅ USB HID Gamepad Interface
- ✅ DMA + Timer-based ADC Sampling
- ✅ Active-low Button Handling
- ✅ LED Indicators for joystick movement
- ❌ Bluetooth HID (planned but not implemented)

---

## 📂 Project Structure
```
STM32_Gamepad_Project/
├── Core/
│   ├── Inc/
│   │   └── main.h
│   ├── Src/
│   │   ├── main.c
│   │   ├── usb_device.c
│   │   └── usbd_custom_hid_if.c
├── USB_DEVICE/
│   └── usbd_customhid.c/h
├── Drivers/
│   └── STM32F4xx_HAL_Driver/
└── README.md <-- (this file)
```


# 🕹️ Button Mapping

| Button         | GPIO Pin | HID Bit | Description       |
|----------------|----------|---------|-------------------|
| X              | PB4      | 0       | Action Button     |
| Y              | PB5      | 1       | Action Button     |
| A              | PB2      | 2       | Action Button     |
| B              | PB3      | 3       | Action Button     |
| D-Pad Up       | PB6      | 12      | Directional       |
| D-Pad Down     | PB7      | 13      | Directional       |
| D-Pad Left     | PB8      | 14      | Directional       |
| D-Pad Right    | PB9      | 15      | Directional       |
| Option Button  | PA0      | 9       | Start/Menu button |

- All buttons are **active-low** and polled via GPIO.

---

## 🎮 Joystick Mapping

### Left Joystick (Joystick 1)
- VRx: PB1 → `adcValues[1]`
- VRy: PB0 → `adcValues[0]`

### Right Joystick (Joystick 2)
- VRx: PA6 → `adcValues[2]`
- VRy: PA7 → `adcValues[3]`

### LED Indicators
- PC13 toggles when any button is pressed.
- PC10 and PA10 toggle depending on joystick movement.

---

## 📏 ADC Details
- **Resolution**: 12-bit (0–4095)
- **Reference Voltage**: 3.3V
- **Mode**: Circular DMA
- **Trigger**: TIM3 Timer

### 🧮 Joystick Processing
```c
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
    return (uint8_t)(val + 128); // Shift to 0–255 range
}
```

---

## 📤 HID Report Descriptor (Xbox360 Style)
```text
0x05, 0x01,        // Usage Page (Generic Desktop)
0x09, 0x05,        // Usage (Gamepad)
0xA1, 0x01,        // Collection (Application)
  0x05, 0x09,      // Usage Page (Button)
  0x19, 0x01,      // Usage Minimum (Button 1)
  0x29, 0x10,      // Usage Maximum (Button 16)
  0x15, 0x00,      // Logical Minimum (0)
  0x25, 0x01,      // Logical Maximum (1)
  0x75, 0x01,      // Report Size (1)
  0x95, 0x10,      // Report Count (16)
  0x81, 0x02,      // Input (Data, Variable, Absolute)

  0x05, 0x01,      // Usage Page (Generic Desktop)
  0x09, 0x30,      // Usage (X)
  0x09, 0x31,      // Usage (Y)
  0x09, 0x33,      // Usage (Rx)
  0x09, 0x34,      // Usage (Ry)
  0x15, 0x00,
  0x26, 0xFF, 0x00, // Logical Maximum (255)
  0x75, 0x08,      // Report Size (8)
  0x95, 0x04,      // Report Count (4)
  0x81, 0x02,      // Input (Data, Variable, Absolute)

  0x09, 0x32,      // Usage (Z)
  0x09, 0x35,      // Usage (Rz)
  0x75, 0x08,
  0x95, 0x02,
  0x81, 0x02,
0xC0               // End Collection
```

### 🧾 Report Structure (8 bytes)
| Byte Index | Description      |
|------------|------------------|
| 0          | Buttons LSB       |
| 1          | Buttons MSB       |
| 2          | X (Joystick 1)    |
| 3          | Y (Joystick 1)    |
| 4          | Rx (Joystick 2)   |
| 5          | Ry (Joystick 2)   |
| 6          | Z (Trigger 1)     |
| 7          | Rz (Trigger 2)    |

