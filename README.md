# 🌍 Air Quality Monitoring System using ESP8266, DHT11 & MQ135

This project monitors **temperature**, **humidity**, and **air quality** using NodeMCU (ESP8266), DHT11 sensor, MQ135 gas sensor, and uploads real-time data to **Blynk IoT Platform**.

---

## 🚀 Features

- Real-time temperature and humidity monitoring using DHT11
- Air quality monitoring using MQ135
- Live data updates to Blynk dashboard via WiFi
- Simple and efficient Blynk + ESP8266 integration

---

## 🧰 Hardware Required

| Component       | Quantity |
|----------------|----------|
| NodeMCU ESP8266| 1        |
| DHT11 Sensor   | 1        |
| MQ135 Sensor   | 1        |
| Jumper Wires   | As needed|
| Breadboard     | 1        |

---

## 🔧 Circuit Connections

| Sensor Pin     | NodeMCU Pin |
|----------------|-------------|
| DHT11 Data     | D2 (GPIO4)  |
| MQ135 Analog   | A0          |
| VCC/GND        | 3.3V/GND    |

---

## 📲 Blynk Setup

1. Create a new Template in [Blynk IoT](https://blynk.cloud/)
2. Copy your **Template ID**, **Template Name**, and **Auth Token**
3. Set up three virtual pins:
   - V0: Temperature
   - V1: Humidity
   - V2: Air Quality

---

## 🧪 Libraries Required

Install these libraries from **Library Manager**:

- `ESP8266WiFi`
- `BlynkSimpleEsp8266`
- `DHT sensor library`
- `MQ135` (available via GitHub or local install)

---

## 💻 Uploading Code

1. Open `AirQualityMonitoring.ino` in Arduino IDE
2. Select board: `NodeMCU 1.0 (ESP-12E)`
3. Enter your WiFi SSID, Password, and Blynk Auth Token
4. Connect NodeMCU and upload

---

## 📸 Sample Output (Serial Monitor)

```
Temperature: 28.50 °C, Humidity: 60.00 %, Air Quality (Raw): 356
```

---
