#pragma once

#include <ESPAsyncWebServer.h>

class WebManager
{
public:
    void begin();

    void update();

private:
    AsyncWebServer server = AsyncWebServer(80);
};