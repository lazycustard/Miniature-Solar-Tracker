# 🌞 Miniature Solar Tracker

This is an Arduino-based Miniature Solar Tracker that uses LDRs (Light Dependent Resistors) and a servo motor to follow the direction of the brightest light. It also includes an ADXL345 accelerometer for monitoring real-time orientation.

---

## 📌 Project Overview

The tracker reads values from LDRs placed on the left and right sides. Based on the light intensity, a servo motor adjusts its position to point toward the brighter side. When both sides are dim, the servo centers itself. Simultaneously, the ADXL345 accelerometer records 3-axis orientation data and prints it to the serial monitor.

---

## 🔧 Features

- Light-based servo movement
- Automatic centering in low-light conditions
- Real-time orientation data from the ADXL345
- Easy to build and beginner-friendly code

---

## 🧰 Components Required

| Component                | Quantity |
|--------------------------|----------|
| Arduino Uno              | 1        |
| LDR                      | 3        |
| 10kΩ Resistors           | 3        |
| SG90 Servo Motor         | 1        |
| ADXL345 Accelerometer    | 1        |
| Breadboard & Jumper Wires| As needed |

---

## 🔌 Circuit Connections

### LDRs (Analog Inputs)
- Left LDR → A1  
- Right LDR → A0  
- Top LDR (optional) → A3  
*(Each LDR is connected in a voltage divider circuit with a 10kΩ resistor)*

### Servo Motor
- Signal → Pin 9  
- VCC → 5V  
- GND → GND

### ADXL345 (I2C Interface)
- SDA → A4  
- SCL → A5  
- VCC → 3.3V or 5V (based on module)  
- GND → GND

---

## 📦 Libraries Used

Install these libraries using the Arduino Library Manager:

- `Adafruit Sensor`
- `Adafruit ADXL345`
- `Wire.h` *(included by default)*
- `Servo.h` *(included by default)*

---

## 🧠 How It Works

1. The Arduino reads analog values from LDRs.
2. If one LDR reads significantly higher than the other, the servo turns toward that side.
3. If both LDRs are under a certain brightness threshold, the servo resets to center (90°).
4. The ADXL345 accelerometer reads X, Y, Z orientation values and sends them to the serial monitor.

---

## 🌀 Logic Flow

```text
1. Read LDR values (left and right)
2. Compare values:
   - Left brighter → servo to 180°
   - Right brighter → servo to 0°
   - Both dim → servo to 90°
3. Read accelerometer data
4. Print LDR + accelerometer values to Serial Monitor
5. Delay for 1 second


```
---
## 🚀 Future Improvements

- Add vertical tracking using the top LDR and a second servo
- Add data logging or integrate an IoT dashboard (e.g., Blynk or Thingspeak)
- Display servo angle and sensor values on an LCD screen.

---

## 📄 License

This project is licensed under the **MIT License**.  

