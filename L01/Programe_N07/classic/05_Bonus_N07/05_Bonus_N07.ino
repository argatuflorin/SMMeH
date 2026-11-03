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
// Extensie: al doilea LED, cu rezistor propriu 330 ohmi
const int DIAG_PIN = 16;
unsigned long lastChange = 0;
bool ledOn = true;
void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(DIAG_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  digitalWrite(LED_PIN, HIGH);
  lastChange = millis();
}
void loop() {
  unsigned long now = millis();
  unsigned long interval = ledOn ? T_ON : T_OFF;
  if (now - lastChange >= interval) {
    lastChange = now;
    ledOn = !ledOn;
    digitalWrite(LED_PIN, ledOn ? HIGH : LOW);
  }
  bool pressed = digitalRead(BUTTON_PIN) == LOW;
  digitalWrite(DIAG_PIN, pressed ? HIGH : LOW);
}
