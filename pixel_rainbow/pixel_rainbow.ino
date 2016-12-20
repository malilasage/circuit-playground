#include <Adafruit_NeoPixel.h>

int pixelPin = 17;
int nPixels = 10;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(nPixels, pixelPin, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
}

void loop() {
  int g = 5;
  int r = 30;
  int b = 20;
  for(int i = 0; i < nPixels; i++) {
    strip.setPixelColor(i, strip.Color(g, r, b));
    strip.setBrightness(40);
    g += 20;
    r += 10;
    b += 15;
    strip.show();
  }
}

