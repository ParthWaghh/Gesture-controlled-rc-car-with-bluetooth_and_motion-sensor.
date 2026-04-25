#include <Wire.h>
#include <MPU6050.h>
#include <SoftwareSerial.h>

MPU6050 mpu;
SoftwareSerial bt(2, 3); // RX, TX

void setup() {
  Wire.begin();
  mpu.initialize();
  bt.begin(9600);
}

void loop() {
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);

  if (ay > 8000) bt.println("F");      // Forward
  else if (ay < -8000) bt.println("B"); // Backward
  else if (ax > 8000) bt.println("R");  // Right
  else if (ax < -8000) bt.println("L"); // Left
  else bt.println("S");                 // Stop

  delay(200);
}
