#include <Arduino.h>
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <WiFiManager.h>
#include <ArduinoOTA.h>

#include "AudioManager.h"
#include "DisplayManager.h"
#include "WebManager.h"
#include "StorageManager.h"
#include "IRManager.h"
#include "LEDManager.h"

AudioManager audio;
DisplayManager display;
WebManager web;
StorageManager storage;
IRManager ir;
LEDManager leds;

void setup()
{
    Serial.begin(115200);

    Wire.begin();

    display.begin();

    display.showBoot();

    storage.begin();

    audio.volume = storage.loadVolume();

    audio.begin();

    WiFiManager wm;

    wm.autoConnect("AudioProcessor");

    ArduinoOTA.setHostname("AudioProcessor");

    ArduinoOTA.begin();

    web.begin();

    ir.begin();

    leds.begin();

    leds.wifiConnected();

    display.showVolume(audio.volume);
}

void loop()
{
    ArduinoOTA.handle();

    ir.update();

    int vu = analogRead(A0);

    leds.vuMeter(vu);

    delay(20);
}