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
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(115200);
}
void loop() {
  int raw = digitalRead(BUTTON_PIN);
  bool pressed = (raw == LOW);
  digitalWrite(LED_PIN, pressed ? HIGH : LOW);
  static int previous = -1;
  if (raw != previous) {
    Serial.printf("%lu;N=%d;BTN=%d;LED=%d\n", millis(), N, raw, pressed);
    previous = raw;
  }
  delay(10); // ritm bucla, NU algoritm complet anti-rebond
}
