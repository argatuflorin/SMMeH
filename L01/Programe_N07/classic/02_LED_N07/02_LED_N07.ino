// SMMeH-L01-1.0-N07 | SMMeH | ESP32 clasic WROOM
// Verifica GPIO pe pinout-ul placii exacte. Serial Monitor 115200.
#include <Arduino.h>
const int N = 7;
const int LED_PIN = 18;
const int BUTTON_PIN = 27;
const int DHT_PIN = 4;
const unsigned long T_ON = 1100UL;
const unsigned long T_OFF = 800UL;
const unsigned long T_SENSOR = 3000UL;
void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}
void loop() {
  digitalWrite(LED_PIN, HIGH);
  Serial.printf("%lu;LED_ON;N=%d\n", millis(), N);
  delay(T_ON);
  digitalWrite(LED_PIN, LOW);
  Serial.printf("%lu;LED_OFF;N=%d\n", millis(), N);
  delay(T_OFF);
}
