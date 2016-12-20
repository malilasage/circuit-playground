//include adafruit neopixel library
#include <Adafruit_NeoPixel.h>

//declare pin
int ledPin = 17;
//declare number of leds on one pin
int pixelNum = 10;
//declare strip of neopixels
Adafruit_NeoPixel  strip = Adafruit_NeoPixel(pixelNum, ledPin, NEO_GRB + NEO_KHZ800);


void setup() {
  // put your setup code here, to run once:
  strip.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  //for each led in strip
  for(int i=0; i<pixelNum; i++){
    strip.setPixelColor(i, strip.Color(70, 50, 150));
    strip.setBrightness(30);
    strip.show();
  }
}
