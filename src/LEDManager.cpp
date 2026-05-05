#include "LEDManager.h"

void LEDManager::begin()
{
    FastLED.addLeds<WS2812B,2,GRB>(leds,16);

    FastLED.clear();
    FastLED.show();
}

void LEDManager::wifiConnected()
{
    for(int i=0;i<16;i++)
    {
        leds[i] = CRGB::Blue;
    }

    FastLED.show();
}

void LEDManager::vuMeter(int value)
{
    int level = map(value,0,1024,0,16);

    for(int i=0;i<16;i++)
    {
        if(i<level)
        {
            leds[i] = CRGB::Green;
        }
        else
        {
            leds[i] = CRGB::Black;
        }
    }

    FastLED.show();
}