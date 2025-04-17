#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <Servo.h>

const int ldrLeftPin = A1;
const int ldrRightPin = A0;
const int ldrTopPin = A3;

Servo myServo;
int servoPin = 9;
int servoAngle = 90;

int ldrThreshold = 400;

int leftLDR = 0;
int rightLDR = 0;

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
float x, y, z;

void setup() {
  Serial.begin(9600);

  if (!accel.begin()) {
    Serial.println("No ADXL345 detected");
    while (1);
  }

  myServo.attach(servoPin);
  myServo.write(servoAngle);
  delay(1000);
}

void loop() {
  leftLDR = analogRead(ldrLeftPin);
  rightLDR = analogRead(ldrRightPin);

  Serial.print("Left LDR: ");
  Serial.print(leftLDR);
  Serial.print(" Right LDR: ");
  Serial.println(rightLDR);

  sensors_event_t event;
  accel.getEvent(&event);
  x = event.acceleration.x;
  y = event.acceleration.y;
  z = event.acceleration.z;

  Serial.print("Accelerometer - X: ");
  Serial.print(x);
  Serial.print(" Y: ");
  Serial.print(y);
  Serial.print(" Z: ");
  Serial.println(z);

  if (leftLDR < ldrThreshold && rightLDR < ldrThreshold) {
    Serial.println("Low light on both sides, centering the servo!");
    servoAngle = 90;
    myServo.write(servoAngle);
  } else if (leftLDR >  ldrThreshold) {
    Serial.println("Light is stronger on the left, moving to the left!");
    servoAngle = 180;
    myServo.write(servoAngle);
  } else if (rightLDR > leftLDR + ldrThreshold) {
    Serial.println("Light is stronger on the right, moving to the right!");
    servoAngle = 0;
    myServo.write(servoAngle);
  }

  delay(1000);
}
