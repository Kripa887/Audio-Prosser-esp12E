#pragma once

#include <EEPROM.h>

class StorageManager
{
public:
    void begin();

    void saveVolume(int value);

    int loadVolume();
};