#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <TDA7439.h>

class AudioManager
{
public:
    void begin();

    void update();

    void apply();

    int volume = 20;
    int bass = 0;
    int mids = 0;
    int treble = 0;
    int balance = 0;
    int input = 1;
    int gain = 0;

private:
    TDA7439 tda;
};