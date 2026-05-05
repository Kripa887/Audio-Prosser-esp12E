#include "WebManager.h"
#include <LittleFS.h>

void WebManager::begin()
{
    LittleFS.begin();

    server.serveStatic("/",LittleFS,"/").setDefaultFile("index.html");

    server.begin();
}

void WebManager::update()
{
}