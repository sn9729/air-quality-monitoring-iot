// Include libraries
#define BLYNK_TEMPLATE_ID ""  // Your Blynk Template ID
#define BLYNK_TEMPLATE_NAME "Air Quality Monitoring"  // Blynk Template Name

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include "MQ135.h"

// WiFi Credentials
char ssid[] = "MSI 1624";   // Your WiFi SSID
char pass[] = "sanjay123";  // Your WiFi password

// Blynk Auth Token
char auth[] = "pK21mVHtNJJZB86DwlLD8PlCrtjZIdmv";  // Your Blynk Auth Token

// Sensor setup
#define DHTPIN 4          // GPIO2 on NodeMCU for DHT11 sensor
#define DHTTYPE DHT11     // Define sensor type as DHT11

DHT dht(DHTPIN, DHTTYPE);
MQ135 gasSensor(A0);  // Define MQ135 analog pin (A0)
BlynkTimer timer;     // Blynk timer to call functions periodically

void sendSensorData() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int air_quality = analogRead(A0);  

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" °C, Humidity: ");
  Serial.print(h);
  Serial.print(" %, Air Quality (Raw): ");
  Serial.println(air_quality);  // Show raw analog value of air quality

  Blynk.virtualWrite(V0, t);   // Temperature
  Blynk.virtualWrite(V1, h);   // Humidity
  Blynk.virtualWrite(V2, air_quality); // Air Quality (Raw)
}

void setup() {
  Serial.begin(115200);   // Start Serial communication at 115200 baud rate
  Blynk.begin(auth, ssid, pass);   // Connect to Blynk App
  dht.begin();   // Initialize the DHT sensor
  timer.setInterval(1000L, sendSensorData);  // Call every 1 second
}

void loop() {
  Blynk.run();  // Run Blynk
  timer.run();  // Run Blynk timer
}
