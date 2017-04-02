#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_NeoPixel.h>

int LED_PIN = 6;
int N_LED = 1;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LED, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
}

void loop() {
  strip.setBrightness(50);
  strip.setPixelColor(0, 155, 0, 155);
  strip.show();
}

