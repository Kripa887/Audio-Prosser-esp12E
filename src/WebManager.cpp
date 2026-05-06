#include "WebManager.h"
#include <LittleFS.h>
#include <ESP8266WiFi.h>

extern int volume;
extern int bass;
extern int mid;
extern int treble;
extern int balance;
extern int inputChannel;

void WebManager::begin()
{
    LittleFS.begin();

    server.serveStatic("/",LittleFS,"/").setDefaultFile("index.html");

    server.on("/set",HTTP_GET,[](AsyncWebServerRequest *request)
    {
        if(request->hasParam("volume"))
        {
            volume = request->getParam("volume")->value().toInt();
        }

        if(request->hasParam("bass"))
        {
            bass = request->getParam("bass")->value().toInt();
        }

        if(request->hasParam("mid"))
        {
            mid = request->getParam("mid")->value().toInt();
        }

        if(request->hasParam("treble"))
        {
            treble = request->getParam("treble")->value().toInt();
        }

        if(request->hasParam("balance"))
        {
            balance = request->getParam("balance")->value().toInt();
        }

        request->send(200,"text/plain","OK");
    });

    server.on("/input",HTTP_GET,[](AsyncWebServerRequest *request)
    {
        if(request->hasParam("id"))
        {
            inputChannel = request->getParam("id")->value().toInt();
        }

        request->send(200,"text/plain","INPUT OK");
    });

    server.on("/vu",HTTP_GET,[](AsyncWebServerRequest *request)
    {
        int vu = analogRead(A0);

        int level = map(vu,0,1024,0,100);

        request->send(200,"text/plain",String(level));
    });

    server.on("/status",HTTP_GET,[](AsyncWebServerRequest *request)
    {
        String json = "{";

        json += "\"ip\":\"" + WiFi.localIP().toString() + "\",";
        json += "\"rssi\":" + String(WiFi.RSSI()) + ",";
        json += "\"volume\":" + String(volume);

        json += "}";

        request->send(200,"application/json",json);
    });

    server.begin();
}

void WebManager::update()
{
}