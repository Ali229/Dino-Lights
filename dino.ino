// #include <FastLED.h>
#include <Arduino.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.write("Hello");
  delay(3000);
}
