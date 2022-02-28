#include <FastLED.h>

#define LED_PIN_DINO_1 12
#define NUM_LEDS_DINO_1 22
CRGB leds_DINO_1[NUM_LEDS_DINO_1];

#define TRANSITION_TIME 10 //seconds
#define BRIGHTNESS 50
int new_color[3];

#define R 0
#define G 1
#define B 2

void setup() {
  delay(3000); //power-up safety delay
  Serial.begin(115200);
  FastLED.addLeds < WS2812, LED_PIN_DINO_1, GRB > (leds_DINO_1, NUM_LEDS_DINO_1).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();
}

void loop() {
  getColor();
  printNewColor();

  while (leds_DINO_1[0].r != new_color[R] || leds_DINO_1[0].g != new_color[G] || leds_DINO_1[0].b != new_color[B]) {
    for (int l = 0; l < NUM_LEDS_DINO_1; l++) {

      if (leds_DINO_1[l].r < new_color[R]) {
        leds_DINO_1[l].r++;
      } else if (leds_DINO_1[l].r > new_color[R]) {
        leds_DINO_1[l].r--;
      }

      if (leds_DINO_1[l].g < new_color[G]) {
        leds_DINO_1[l].g++;
      } else if (leds_DINO_1[l].g > new_color[G]) {
        leds_DINO_1[l].g--;
      }

      if (leds_DINO_1[l].b < new_color[B]) {
        leds_DINO_1[l].b++;
      } else if (leds_DINO_1[l].b > new_color[B]) {
        leds_DINO_1[l].b--;
      }
    }
    FastLED.show();
    printCurrentColor();
    delay(39);
  }
}

void printCurrentColor() {
  Serial.println("Current color: ");
  Serial.print(leds_DINO_1[0].r);
  Serial.print(" ");
  Serial.print(leds_DINO_1[0].g);
  Serial.print(" ");
  Serial.println(leds_DINO_1[0].b);
}

void printNewColor() {
  Serial.println("New color: ");
  Serial.print(new_color[0]);
  Serial.print(" ");
  Serial.print(new_color[1]);
  Serial.print(" ");
  Serial.println(new_color[2]);
}

void getColor() {
  new_color[0] = rand() % 255;
  new_color[1] = rand() % 255;
  new_color[2] = rand() % 255;
}