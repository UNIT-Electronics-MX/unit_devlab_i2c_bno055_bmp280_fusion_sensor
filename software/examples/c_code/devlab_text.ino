#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <Adafruit_BMP280.h>
#include <utility/imumaths.h>

// BNO055: orientación y movimiento
Adafruit_BNO055 bno(55, 0x28, &Wire);

// BMP280: temperatura y presión
Adafruit_BMP280 bmp;
Adafruit_Sensor* bmp_temp = bmp.getTemperatureSensor();
Adafruit_Sensor* bmp_pressure = bmp.getPressureSensor();

void setup() {
  Serial.begin(115200);
  while (!Serial);

  // Inicializar BNO055
  if (!bno.begin()) {
    Serial.println("{\"error\":\"BNO055 not detected\"}");
    while (1);
  }
  delay(1000);  // Estabilizar BNO055

  // Inicializar BMP280 en dirección 0x76
  if (!bmp.begin(0x76)) {
    Serial.println("{\"error\":\"BMP280 not detected at 0x76\"}");
    while (1);
  }

  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,
                  Adafruit_BMP280::SAMPLING_X2,
                  Adafruit_BMP280::SAMPLING_X16,
                  Adafruit_BMP280::FILTER_X16,
                  Adafruit_BMP280::STANDBY_MS_500);
}

void loop() {
  // Eventos del BNO055
  sensors_event_t orientation, gyro, linearAccel, magnetometer, accel, gravity;
  bno.getEvent(&orientation,  Adafruit_BNO055::VECTOR_EULER);
  bno.getEvent(&gyro,         Adafruit_BNO055::VECTOR_GYROSCOPE);
  bno.getEvent(&linearAccel,  Adafruit_BNO055::VECTOR_LINEARACCEL);
  bno.getEvent(&magnetometer, Adafruit_BNO055::VECTOR_MAGNETOMETER);
  bno.getEvent(&accel,        Adafruit_BNO055::VECTOR_ACCELEROMETER);
  bno.getEvent(&gravity,      Adafruit_BNO055::VECTOR_GRAVITY);

  // BMP280
  sensors_event_t temp_event, pressure_event;
  bmp_temp->getEvent(&temp_event);
  bmp_pressure->getEvent(&pressure_event);

  // Calibración BNO055
  int8_t temp_bno = bno.getTemp();
  uint8_t sys, gyroCal, accelCal, magCal;
  bno.getCalibration(&sys, &gyroCal, &accelCal, &magCal);

  Serial.println("----- LECTURA SENSORES -----");

  // BMP280
  Serial.print("BMP280 Temp (C): ");
  Serial.println(temp_event.temperature, 2);

  Serial.print("BMP280 Pressure (hPa): ");
  Serial.println(pressure_event.pressure, 2);

  // BNO055 - orientación (Euler)
  Serial.print("BNO055 Orientation (deg) X: ");
  Serial.print(orientation.orientation.x, 2);
  Serial.print("  Y: ");
  Serial.print(orientation.orientation.y, 2);
  Serial.print("  Z: ");
  Serial.println(orientation.orientation.z, 2);

  // BNO055 - giroscopio
  Serial.print("BNO055 Gyro (rad/s) X: ");
  Serial.print(gyro.gyro.x, 2);
  Serial.print("  Y: ");
  Serial.print(gyro.gyro.y, 2);
  Serial.print("  Z: ");
  Serial.println(gyro.gyro.z, 2);

  // BNO055 - aceleración lineal
  Serial.print("BNO055 Linear Accel (m/s^2) X: ");
  Serial.print(linearAccel.acceleration.x, 2);
  Serial.print("  Y: ");
  Serial.print(linearAccel.acceleration.y, 2);
  Serial.print("  Z: ");
  Serial.println(linearAccel.acceleration.z, 2);

  // BNO055 - magnetómetro
  Serial.print("BNO055 Magnetometer (uT) X: ");
  Serial.print(magnetometer.magnetic.x, 2);
  Serial.print("  Y: ");
  Serial.print(magnetometer.magnetic.y, 2);
  Serial.print("  Z: ");
  Serial.println(magnetometer.magnetic.z, 2);

  // BNO055 - aceleración total
  Serial.print("BNO055 Accel (m/s^2) X: ");
  Serial.print(accel.acceleration.x, 2);
  Serial.print("  Y: ");
  Serial.print(accel.acceleration.y, 2);
  Serial.print("  Z: ");
  Serial.println(accel.acceleration.z, 2);

  // BNO055 - gravedad
  Serial.print("BNO055 Gravity (m/s^2) X: ");
  Serial.print(gravity.acceleration.x, 2);
  Serial.print("  Y: ");
  Serial.print(gravity.acceleration.y, 2);
  Serial.print("  Z: ");
  Serial.println(gravity.acceleration.z, 2);

  // Temp interna + calibración
  Serial.print("BNO055 Internal Temp (C): ");
  Serial.println(temp_bno);

  Serial.print("Calibration SYS: ");
  Serial.print(sys);
  Serial.print("  GYRO: ");
  Serial.print(gyroCal);
  Serial.print("  ACCEL: ");
  Serial.print(accelCal);
  Serial.print("  MAG: ");
  Serial.println(magCal);

  Serial.println("----------------------------");
  Serial.println();

  delay(500);
}
