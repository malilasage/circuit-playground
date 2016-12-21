#include <Adafruit_NeoPixel.h>

int pixelPin = 17;
int nPixels = 10;
enum direction { FORWARD, REVERSE };
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(nPixels, pixelPin, NEO_RGB + NEO_KHZ800);

class NeoPatterns : public Adafruit_NeoPixel
{
  public:
  direction Direction;
  
  unsigned long Interval;
  unsigned long lastUpdate;

  uint16_t TotalSteps;
  uint16_t Index;

  void (*OnComplete)();

  NeoPatterns(uint16_t pixels, uint8_t pin, uint8_t type):Adafruit_NeoPixel(pixels, pin, type)
  {
//    OnComplete = callback;
  }

  void Update()
  {
    if((millis() - lastUpdate) > Interval)
    {
      lastUpdate = millis();
      RainbowCycleUpdate();
    }
  }

  void Increment()
  {
    Index++;
    if(Index >= TotalSteps)
    {
      Index = 0;
      if(OnComplete != NULL)
      {
        OnComplete();
      }
    }
  }
  void RainbowCycle(uint8_t interval, direction dir = FORWARD)
  {
    Interval = interval;
    TotalSteps = 255;
    Index = 0;
    Direction = dir;
  }

    uint32_t Wheel(byte WheelPos)
    {
        WheelPos = 255 - WheelPos;
        if(WheelPos < 85)
        {
            return Color(255 - WheelPos * 3, 0, WheelPos * 3);
        }
        else if(WheelPos < 170)
        {
            WheelPos -= 85;
            return Color(0, WheelPos * 3, 255 - WheelPos * 3);
        }
        else
        {
            WheelPos -= 170;
            return Color(WheelPos * 3, 255 - WheelPos * 3, 0);
        }
    }

  void RainbowCycleUpdate()
  {
    for(int i=0; i<numPixels(); i++)
    {
      setPixelColor(i, Wheel(((i * 256 / numPixels()) + Index & 255)));
    }
    show();
    Increment();
  }
};

void StripComplete();

NeoPatterns Strip(10, 17, NEO_GRB + NEO_KHZ800); //&stripComplete

void setup()
{
  Strip.begin();
  Strip.RainbowCycle(3);
}

void loop()
{
  Strip.Update();
}


