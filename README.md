# BNO055 BMP28 Module

## Introduction
This module combines two sensors on a single board:

- **BNO055**: 9-DOF absolute orientation sensor (accelerometer, gyroscope, magnetometer) with on-board sensor fusion.  
- **BMP280**: high-precision barometric pressure and temperature sensor.

Perfect for robotics, inertial navigation, drones, environmental monitoring and IoT projects.

<div align="center">
    <a href="#"><img src="hardware/resources/img/unit_top_v_00x_sku_EU0091.png" width="500px"><br/>BNO055 + BMO280 Module</a>
    <br/>


</div>

## Features

- **BNO055**  
  - On-chip sensor fusion (`quaternions`, `Euler angles`, `gravity vectors`, etc.)  
  - **Accelerometer** ranges: ±2/4/8/16 g  
  - **Gyroscope** ranges: ±125/250/500/1000/2000 °/s  
  - **Magnetometer** ranges: ±1.3/1.9/2.5/4.0/4.7/5.6/8.1 gauss  
  - **Interfaces**: `I²C`, `UART`, `SPI` (select via PS0/PS1)  

- **BMP280**  
  - Pressure range: 300…1100 hPa (±10…+1 m)  
  - Temperature accuracy: ±1 °C  
  - Interfaces: I²C (up to 3.4 MHz) or SPI (up to 10 MHz)  
  
- **SWD programming/debugging** via SWCLK/SWDIO  
- **JST-SH QWIIC connector** (GND, VCC, SDA, SCL)  