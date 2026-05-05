#include "DisplayManager.h"

void DisplayManager::begin()
{
    lcd.init();

    lcd.backlight();
}

void DisplayManager::showBoot()
{
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("SoundHolics");

    lcd.setCursor(0,1);
    lcd.print("ESP12E Ready");
}

void DisplayManager::showVolume(int value)
{
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Volume:");
    lcd.print(value);

    int bars = map(value,0,48,0,16);

    lcd.setCursor(0,1);

    for(int i=0;i<bars;i++)
    {
        lcd.write(255);
    }
}

void DisplayManager::showBass(int value)
{
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Bass:");
    lcd.print(value);
}

void DisplayManager::showMid(int value)
{
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Mid:");
    lcd.print(value);
}

void DisplayManager::showTreble(int value)
{
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Treble:");
    lcd.print(value);
}

void DisplayManager::showInput(int value)
{
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Input:");
    lcd.print(value);
}