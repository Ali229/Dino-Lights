#include <FastLED.h>

#define DATA_PIN 12
#define NUM_LEDS 100
CRGB leds[NUM_LEDS];



void setup() {
  Serial.begin(115200);
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  Serial.write("Lights turned on");
}

void loop() {
       // Move a single white led 
   for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed++) {
      // Turn our current led on to white, then show the leds
      leds[whiteLed] = CRGB::White;
      leds[whiteLed+1] = CRGB::White;
      leds[whiteLed+2] = CRGB::White;
      leds[whiteLed+3] = CRGB::White;
      leds[whiteLed+4] = CRGB::White;
      leds[whiteLed+5] = CRGB::White;
      // Show the leds (only one of which is set to white, from above)
      FastLED.show();

      // Wait a little bit
      delay(100);

      // Turn our current led back to black for the next loop around
      leds[whiteLed] = CRGB::Black;
      leds[whiteLed+1] = CRGB::Black;
      leds[whiteLed+2] = CRGB::Black;
      leds[whiteLed+3] = CRGB::Black;
      leds[whiteLed+4] = CRGB::Black;
      leds[whiteLed+5] = CRGB::Black;
   }
}
