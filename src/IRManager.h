#pragma once

#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

class IRManager
{
public:
    void begin();

    void update();

private:
    IRrecv irrecv = IRrecv(0);

    decode_results results;
};