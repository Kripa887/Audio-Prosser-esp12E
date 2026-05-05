#pragma once

#include <FastLED.h>

class LEDManager
{
public:
    void begin();

    void wifiConnected();

    void vuMeter(int value);

private:
    CRGB leds[16];
};