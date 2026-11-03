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
void setup() {
  Serial.begin(115200);
  delay(1500); // timp pentru deschiderea portului
  Serial.printf("SMMeH L01 N=%d\n", N);
}
void loop() {
  Serial.printf("uptime_ms=%lu; N=%d\n", millis(), N);
  delay(1000);
}
