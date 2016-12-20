#include <Adafruit_NeoPixel.h>

int pixelPin = 17;
int nPixels = 10;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(nPixels, pixelPin, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
}

void loop() {
  for(int i = 0; i < nPixels; i++) {
    int g = random(255);
    int r = random(255);
    int b = random(255);
    strip.setPixelColor(i, strip.Color(g, r, b));
    strip.setBrightness(40);
//    g += 20;
//    r += 10;
//    b += 15;
    strip.show();
  }
}

