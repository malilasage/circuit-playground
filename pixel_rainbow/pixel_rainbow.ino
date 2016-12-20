#include <Adafruit_NeoPixel.h>

int pixelPin = 17;
int nPixels = 10;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(nPixels, pixelPin, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
//  Serial.begin(9600);
//  Serial.print('hey');
}

void loop() {
  for(int i=0; i<nPixels; i++) {
    int r = 25 * i;
    int g = 25;
    int b = 75;
    strip.setPixelColor(i, strip.Color(r, g, b));
    strip.setBrightness(60);
    strip.show();
  }

}

