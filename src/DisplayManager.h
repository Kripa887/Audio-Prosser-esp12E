#pragma once

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class DisplayManager
{
public:
    void begin();

    void showBoot();

    void showVolume(int value);

    void showBass(int value);

    void showMid(int value);

    void showTreble(int value);

    void showInput(int value);

private:
    LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,16,2);
};