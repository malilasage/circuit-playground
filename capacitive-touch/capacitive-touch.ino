#include <Adafruit_CircuitPlayground.h>
 
#define CAP_THRESHOLD   50
#define DEBOUNCE        250
int Index = 1;
 
////////////////////////////////////////////////////////////////////////////
boolean capButton(uint8_t pad) {
  if (CircuitPlayground.readCap(pad) > CAP_THRESHOLD) {
    return true;  
  } else {
    return false;
  }
}
 
////////////////////////////////////////////////////////////////////////////
void setup() {
  // Initialize serial.
  Serial.begin(9600); 
  
  // Initialize Circuit Playground library.
  CircuitPlayground.begin();
}
 
////////////////////////////////////////////////////////////////////////////
void loop() {
  // Check if capacitive touch exceeds threshold.
  if (capButton(1)) {
 
      // Print message.
      Serial.println("Touched!");
      for(int i=0; i<10; i++)
      {
        CircuitPlayground.setPixelColor(i, (255 - Index*20), ((1)*(Index*25)), (1 + Index*10));
      }
      Index++;
      // But not too often.
      delay(DEBOUNCE); 
  }
}
