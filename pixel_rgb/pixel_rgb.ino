#include <Adafruit_NeoPixel.h>

int pin = 17;
int nPixels = 10;

class NeoPatterns : public Adafruit_NeoPixel
{
  public:
  
  unsigned long Interval;
  unsigned long lastUpdate;
  uint16_t Index;

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
  
  NeoPatterns(uint16_t pixels, uint8_t pin, uint8_t type):Adafruit_NeoPixel(pixels, pin, type){}

  void Update()
  {
    if((millis() - lastUpdate) > Interval)
    {
      lastUpdate = millis();
      cycleUpdate();
    }
  }
  
  void cycle(uint8_t interval)
  {
    Interval = interval;
    Index = 0;
  }
  
  void cycleUpdate()
  {
    for(int i=0; i<numPixels(); i++)
    {
    setPixelColor(i, Color(colors[Index][0], colors[Index][1], colors[Index][2]));
    setBrightness(40);
    }
    show();
    Index++;
  }
  
};

NeoPatterns Strip(nPixels, pin, NEO_GRB + NEO_KHZ800);


void setup()
{
  Strip.begin();
  Strip.cycle(5);
}

void loop()
{
  Strip.Update();
}

