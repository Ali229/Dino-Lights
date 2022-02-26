#include <FastLED.h>

#define NUM_LEDS 22

void setup() {
  Serial.begin(115200);
  Serial.write("Lights turned on");
}

void loop() {
  Serial.write("HELLO");
  delay(2000);
  //todo
}
