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
  | **Feature**                  | **Description**                                        |
  |------------------------------|--------------------------------------------------------|
  | **On-chip sensor fusion**    | `quaternions`, `Euler angles`, `gravity vectors`, etc. | 
  | **Accelerometer** ranges     | ±2/4/8/16 g                                            |  
  | **Gyroscope** ranges         | ±125/250/500/1000/2000 °/s                             |
  | **Magnetometer** ranges      | ±1.3/1.9/2.5/4.0/4.7/5.6/8.1 gauss                     | 
  | **Protocol**                 | `I²C`, `UART` (select via PS0/PS1)                     | 

- **BMP280**  

  | **Feature**              | **Description**            |
  |--------------------------|----------------------------|
  | **Pressure range**       | 300…1100 hPa (±10…+1 m)    |
  | **Temperature accuracy** | ±1 °C                      |
  | **Protocol**             | `I²C`, `UART`, `SWD`       |
  
- **SWD programming/debugging** via SWCLK/SWDIO  
- **JST-SH QWIIC connector** (GND, VCC, SDA, SCL)  


## Module Applications

| Application                          | Description                                                                 |
|--------------------------------------|-----------------------------------------------------------------------------|
| 📈 Portable weather station          | Measures temperature, humidity, and pressure accurately.                    |
| 🪂 Altimeter / variometer            | Calculates altitude based on atmospheric pressure.                          |
| 🧍 Posture tracking                  | Detects body tilt or rotation.                                              |
| 🛰️ Inertial navigation               | Tracks movement and orientation without GPS.                                |
| 🕹️ Augmented / virtual reality       | Provides orientation for 3D environments.                                   |
| 🚁 Flight controller                 | Stabilization for drones or robots.                                         |
| 🤖 Gesture interface                 | Uses motion to control devices.                                             |
| 🌐 IoT environmental logging         | Collects and transmits environmental conditions.                            |


## ✅ Recommendations

- 🔋 Recommended power: 3.3 V.
- 🖥️ Use **Processing** or **Unity** for 3D visualization.

---

## Documentation and Setup

### Overview
This repository contains firmware and documentation for integrating the BMM150 magnetometer into your project. The examples provided demonstrate sensor configuration, data acquisition, and interfacing via both I²C and SPI.

### Installation
1. Clone the repository:
   ```
   git clone git@github.com:UNIT-Electronics-MX/unit_bno055_bmp280.git
   ```
2. Navigate to the project directory:
   ```
   cd ./unit_bno055_bmp280
   ```
3. Follow the platform-specific setup instructions detailed in the project documentation.

### Usage
Include the sensor initialization and configuration routines in your main project file. Sample code snippets and detailed explanations can be found in the documentation folder of the repository.


## Support
For any issues or further assistance, please open an issue on the GitHub repository or contact our support team.


## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Resources