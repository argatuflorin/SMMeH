// SMMeH-L01-1.0-N07 | SMMeH | ESP32-S3
// Verifica GPIO pe pinout-ul placii exacte. Serial Monitor 115200.
#include <Arduino.h>
const int N = 7;
const int LED_PIN = 18;
const int BUTTON_PIN = 17;
const int DHT_PIN = 16;
const unsigned long T_ON = 1100UL;
const unsigned long T_OFF = 800UL;
const unsigned long T_SENSOR = 3000UL;
#include <DHT.h>
DHT dht(DHT_PIN, DHT22);
unsigned long lastRead = 0;
void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("t_ms,N,T_C,UR_pct,stare");
}
void loop() {
  unsigned long now = millis();
  if (now - lastRead >= T_SENSOR) {
    lastRead = now;
    float t = dht.readTemperature();
    float h = dht.readHumidity();
    if (isnan(t) || isnan(h)) {
      Serial.printf("%lu,%d,,,EROARE\n", now, N);
    } else {
      Serial.printf("%lu,%d,%.1f,%.1f,OK\n", now, N, t, h);
    }
  }
}
