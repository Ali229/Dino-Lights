#include <FastLED.h>
#define LED_PIN_6 12
#define LED_PIN_8 14
#define LED_PIN_10 27
#define NUM_LEDS_6 22
#define NUM_LEDS_8 27
#define NUM_LEDS_10 22
#define BRIGHTNESS 5
#define LED_TYPE WS2812
#define COLOR_ORDER GRB
CRGB leds_6[NUM_LEDS_6];
CRGB leds_8[NUM_LEDS_8];
CRGB leds_10[NUM_LEDS_10];
#define UPDATES_PER_SECOND 2
const int ldrPin = A0;
CRGBPalette16 currentPalette;
TBlendType currentBlending;
extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;
void setup() {
delay( 3000 ); // power-up safety delay
FastLED.addLeds<LED_TYPE, LED_PIN_6, COLOR_ORDER>(leds_6,
NUM_LEDS_6).setCorrection( TypicalLEDStrip );
FastLED.setBrightness( BRIGHTNESS );
delay( 3000 ); // power-up safety delay
FastLED.addLeds<LED_TYPE, LED_PIN_8, COLOR_ORDER>(leds_8,
NUM_LEDS_8).setCorrection( TypicalLEDStrip );
FastLED.setBrightness( BRIGHTNESS );
delay( 3000 ); // power-up safety delay
FastLED.addLeds<LED_TYPE, LED_PIN_10, COLOR_ORDER>(leds_10,
NUM_LEDS_10).setCorrection( TypicalLEDStrip );
FastLED.setBrightness( BRIGHTNESS );
currentPalette = RainbowColors_p;
currentBlending = LINEARBLEND;
Serial.begin(115200);
pinMode(ldrPin, INPUT);
}
void loop()
{
int ldrStatus = analogRead(ldrPin);
Serial.println(ldrStatus);
delay(500);
ChangePalettePeriodically();
static uint8_t startIndex = 0;
startIndex = startIndex + 1; /* motion speed */
FillLEDsFromPaletteColors( startIndex);
FastLED.show();
FastLED.delay(1000 / UPDATES_PER_SECOND);
}
void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
uint8_t brightness = 255;
for( int i = 0; i < NUM_LEDS_6; ++i) {
leds_6[i] = ColorFromPalette( currentPalette, colorIndex, brightness,
currentBlending);
colorIndex += 3;
}
for( int i = 0; i < NUM_LEDS_8; ++i) {
leds_8[i] = ColorFromPalette( currentPalette, colorIndex, brightness,
currentBlending);
colorIndex += 3;
}
for( int i = 0; i < NUM_LEDS_10; ++i) {
leds_10[i] = ColorFromPalette( currentPalette, colorIndex, brightness,
currentBlending);
colorIndex += 3;
}
}
void ChangePalettePeriodically()
{
uint8_t secondHand = (millis() / 1000) % 60;
static uint8_t lastSecond = 99;
if( lastSecond != secondHand) {
lastSecond = secondHand;
if( secondHand == 0) { currentPalette = RainbowColors_p;
currentBlending = LINEARBLEND; }
}
}
const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM =
{
CRGB::Red,
CRGB::Gray, // 'white' is too bright compared to red and blue
CRGB::Blue,
CRGB::Black,
CRGB::Red,
CRGB::Gray,
CRGB::Blue,
CRGB::Black,
CRGB::Red,
CRGB::Red,
CRGB::Gray,
CRGB::Gray,
CRGB::Blue,
CRGB::Blue,
CRGB::Black,
CRGB::Black
};