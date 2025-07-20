# 🕹️ STM32F411 USB Game Controller

[![Platform](https://img.shields.io/badge/platform-STM32F411CEU6-blue)](https://www.st.com/en/microcontrollers-microprocessors/stm32f411ce.html)
[![USB HID](https://img.shields.io/badge/interface-USB%20HID-green)]()
[![License](https://img.shields.io/badge/license-MIT-lightgrey)]()

> A fully custom USB game controller built using the STM32F411CEU6 microcontroller. Features 9 buttons, 2 analog joysticks, DMA ADC sampling, and a modified Xbox 360 HID descriptor.

---

## 📸 Final Product
*(Insert image below of your final assembled controller)*

![Final Product](./images/controller.jpg)

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

[... Remaining sections omitted for brevity ...]
