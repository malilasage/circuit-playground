#include <Adafruit_NeoPixel.h>

int pixelPin = 17;
int nPixels = 10;
int colors[10][3] = {
  {153, 0, 0},
  {255, 69, 0},
  {255, 215, 0},
  {127, 255, 0},
  {0, 100, 0},
  {0, 191, 255},
  {0, 0, 128},
  {255, 0, 255},
  {75, 0, 130},
  {255, 192, 203}
};
Adafruit_NeoPixel strip = Adafruit_NeoPixel(nPixels, pixelPin, NEO_GRB + NEO_KHZ800);


void setup() {
  strip.begin();
}

void loop() {
  for(int i=0; i<nPixels; i++){
    strip.setPixelColor(i, strip.Color(colors[i][0], colors[i][1], colors[i][2]));
    strip.setBrightness(40);
  }
  strip.show();
}

