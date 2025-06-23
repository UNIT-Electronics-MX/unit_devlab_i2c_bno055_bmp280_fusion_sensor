---
title: "UNIT BNO055 + BMP280 Module"
version: "1.0"
modified: "2025-06-04"
output: "unit_bno055_bmp280_module.pdf"
subtitle: "Integrated 9-DOF IMU and Barometric Sensor Module for Orientation and Environmental Sensing"
---

<!--
# README_TEMPLATE.md
Este archivo sirve como entrada para generar un PDF técnico estilo datasheet.
Edita las secciones respetando el orden, sin eliminar los encabezados.
-->

<!-- logo -->

# UNIT BNO055 + BMP280 Module

![product](images/top.png)

## Introduction

The UNIT BNO055 + BMP280 Module is a compact, ready-to-use board that combines two powerful sensors: a 9-axis absolute orientation sensor and a high-precision barometric pressure and temperature sensor. The BNO055 integrates an accelerometer, gyroscope, and magnetometer with an onboard microcontroller that performs real-time sensor fusion, delivering orientation data such as quaternions, Euler angles, and gravity vectors directly—eliminating the need for complex processing on the host device.

Complementing this, the BMP280 provides accurate atmospheric pressure and temperature readings, making it well-suited for altitude estimation and environmental monitoring. Together, these sensors enable comprehensive motion and environmental awareness, making the module an excellent choice for robotics, drones, VR/AR systems, and IoT applications where both orientation tracking and environmental data are essential.

## Functional Description

The module provides full 9-DOF sensing with absolute orientation through the BNO055, which includes sensor fusion in hardware, eliminating the need for complex calculations on the host MCU. It supports I²C or UART interfaces for flexible integration.

The BMP280 complements the system by offering accurate barometric pressure and temperature measurements, useful for altimetry and environmental logging. Communication is possible through I²C, UART

The board includes clearly labeled pins and a QWIIC-compatible JST-SH connector for rapid prototyping.

## Electrical Characteristics & Signal Overview

- Operating voltage: 3.3 V (typical)
- Logic compatibility: 3.3 V
- BNO055 interfaces: I2C, UART (selectable via PS0/PS1)
- BMP280 interfaces: I2C, UART, SWD
- The BNO055 sensor is highly configurable, offering an accelerometer that operates at ±2g, ±4g, ±8g, or ±16g, a gyroscope that measures angular velocities from ±125°/s up to ±2000°/s, and a magnetometer with ranges adjustable from ±1.3 gauss to ±8.1 gauss.
- BMP280 pressure range: 300 to 1100 hPa
- BMP280 temperature accuracy: +/-1 degC

## Applications

- Portable weather stations
- Altimeter and variometer systems
- Human posture tracking
- Inertial navigation systems
- VR/AR orientation sensing
- Flight controllers for drones and robotics
- Motion gesture interfaces
- IoT environmental data logging

## Features

- BNO055 on-chip sensor fusion with Euler/quaternion output
- BMP280 pressure and temperature sensing
- Dual sensor integration in compact board
- Selectable UART/I2C interfaces
- SWD debug header
- QWIIC-compatible JST-SH connector
- Breadboard-friendly form factor

## Pin & Connector Layout

| PIN     | Description                         |
|---------|-------------------------------------|
| VCC     | Power supply input (3.3 V)          |
| GND     | Ground                              |
| SDA     | I2C data / UART TX (configurable)   |
| SCL     | I2C clock / UART RX (configurable)  |
| PS0     | Protocol select bit 0               |
| PS1     | Protocol select bit 1               |
| INT     | BNO055 interrupt output             |

## Settings

### Interface Overview

| Interface  | Signals / Pins        | Typical Use                              |
|------------|-----------------------|------------------------------------------|
| I2C        | SDA, SCL              | Communication with microcontroller       |
| UART       | TX, RX (via SDA, SCL) | Alternative communication protocol       |
| GPIO       | PS0, PS1              | Protocol selection for BNO055            |
| Interrupt  | INT                   | Orientation or motion event signaling    |

### Supports

| Symbol  | I/O | Description                            |
|---------|-----|----------------------------------------|
| SDA     | I/O | I2C data / UART TX (shared)            |
| SCL     | I/O | I2C clock / UART RX (shared)           |
| PS0     | I   | BNO055 protocol select (bit 0)         |
| PS1     | I   | BNO055 protocol select (bit 1)         |
| SWDIO   | I/O | SWD data                        |
| SWCLK   | I   | SWD clock                       |
| INT     | O   | Motion/interrupt signal (BNO055)       |

## Block Diagram

![Function Diagram](./images/pinout.png)

## Dimensions

![Dimensions](./images/dimension.png)

## Usage

Works with:

- Arduino (Nano, Mega, Due)
- ESP32, ESP8266
- Raspberry Pi (via I2C)
- STM32 and ARM Cortex-M
- CH552 and other UART/I2C-compatible MCUs
- Unity or Processing (3D visualization)

## Downloads

- [Schematic PDF](../hardware/unit_sch_V_0_0_1_EU0091_bno055_bmp280.pdf)

## Purchase

- [Buy from UNIT Electronics](https://www.uelectronics.com)
