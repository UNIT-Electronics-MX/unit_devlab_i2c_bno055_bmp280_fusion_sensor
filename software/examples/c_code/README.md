# Arduino Project: BMP280 + BNO055 Sensor Fusion Code Explanation

This document provides a line-by-line explanation of an Arduino IDE sketch that uses the **Adafruit BNO055** (9-DOF IMU) and the **BMP280** (temperature and pressure sensor). The program collects and prints sensor data in JSON format via serial communication.

---

## Libraries

```cpp
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <Adafruit_BMP280.h>
#include <utility/imumaths.h>
```

`Wire.h`: Enables I2C communication.

`Adafruit_Sensor.h`: Standardizes sensor APIs.

`Adafruit_BNO055.h` Controls the BNO055 orientation sensor.

`Adafruit_BMP280.h`: Controls the BMP280 pressure and temperature sensor.

`imumaths.h`: Used for vector and quaternion math with the BNO055.

## Sensor Initialization

```cpp
Adafruit_BNO055 bno(55, 0x28, &Wire);
Adafruit_BMP280 bmp;
Adafruit_Sensor* bmp_temp = bmp.getTemperatureSensor();
Adafruit_Sensor* bmp_pressure = bmp.getPressureSensor();
```

Initializes the BNO055 at I2C address `0x28`.

Initializes BMP280 and fetches references to its internal temperature and pressure sensors.

## Setup Function

```cpp
void setup() {
  Serial.begin(115200);
  while (!Serial);
```  

Starts serial communication at 115200 baud.

Waits until the serial port is ready.

```cpp
if (!bno.begin()) {
    Serial.println("{\"error\":\"BNO055 not detected\"}");
    while (1);
  }
```

Initializes the BNO055. If not found, outputs a JSON-formatted error and halts.

```cpp
delay(1000);
```

Waits 1 second to let the BNO055 stabilize.

```cpp
  if (!bmp.begin(0x76)) {
    Serial.println("{\"error\":\"BMP280 not detected at 0x76\"}");
    while (1);
  }
```

Initializes BMP280 at address 0x76. If it fails, another JSON error is printed and execution halts.

```cpp
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,
                  Adafruit_BMP280::SAMPLING_X2,
                  Adafruit_BMP280::SAMPLING_X16,
                  Adafruit_BMP280::FILTER_X16,
                  Adafruit_BMP280::STANDBY_MS_500);
}
```

### Configures BMP280:

- Normal mode

- Low power temp sampling (x2), high power pressure sampling (x16)

- Filtering and standby settings to reduce noise

## Loop Function

```cpp
sensors_event_t orientation, gyro, linearAccel, magnetometer, accel, gravity;
bno.getEvent(&orientation,    Adafruit_BNO055::VECTOR_EULER);
bno.getEvent(&gyro,           Adafruit_BNO055::VECTOR_GYROSCOPE);
bno.getEvent(&linearAccel,    Adafruit_BNO055::VECTOR_LINEARACCEL);
bno.getEvent(&magnetometer,   Adafruit_BNO055::VECTOR_MAGNETOMETER);
bno.getEvent(&accel,          Adafruit_BNO055::VECTOR_ACCELEROMETER);
bno.getEvent(&gravity,        Adafruit_BNO055::VECTOR_GRAVITY);
```

### Retrieves six different measurements from BNO055:

- Euler angles (yaw, pitch, roll)

- Angular velocity (gyroscope)

- Linear acceleration (gravity removed)

- Magnetic field (magnetometer)

- Total acceleration (including gravity)

- Gravity vector alone

```cpp
sensors_event_t temp_event, pressure_event;
bmp_temp->getEvent(&temp_event);
bmp_pressure->getEvent(&pressure_event);
```

Retrieves temperature and pressure readings from BMP28

```cpp
int8_t temp_bno = bno.getTemp();
uint8_t sys, gyroCal, accelCal, magCal;
bno.getCalibration(&sys, &gyroCal, &accelCal, &magCal);
```

### Reads BNO055's internal temperature sensor and its calibration status for:

- System

- Gyroscope

- Accelerometer

- Magnetometer

## JSON Output

```cpp
Serial.print("{");
```

Begins JSON object.

### BMP280 Data

```cpp
Serial.print("\"bmp280\":{\"temperature\":");
Serial.print(temp_event.temperature, 2);
Serial.print(",\"pressure\":");
Serial.print(pressure_event.pressure, 2); Serial.print("},");
```
### BNO055 Sensor Blocks

Each block prints a vector of 3-axis data (`x`, `y`, `z`):

```cpp
Serial.print("\"orientation\":{\"x\":"); ...
Serial.print("\"gyroscope\":{\"x\":"); ...
Serial.print("\"linear_accel\":{\"x\":"); ...
Serial.print("\"magnetometer\":{\"x\":"); ...
Serial.print("\"acceleration\":{\"x\":"); ...
Serial.print("\"gravity\":{\"x\":"); ...
```
### Internal Temperature and Calibration
```cpp
Serial.print("\"bno055_temp\":"); Serial.print(temp_bno); Serial.print(",");
Serial.print("\"calibration\":{\"sys\":"); Serial.print(sys);
Serial.print(",\"gyro\":"); Serial.print(gyroCal);
Serial.print(",\"accel\":"); Serial.print(accelCal);
Serial.print(",\"mag\":"); Serial.print(magCal); Serial.print("}");
```
### Adds internal temperature and calibration statuses to JSON.

```cpp
Serial.println("}");
delay(500);
```

## Application Ideas

- Indoor navigation system

- Environmental monitoring stations

- Orientation-aware weather balloons

- Robotics navigation and stabilization