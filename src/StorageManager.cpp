#include "StorageManager.h"

void StorageManager::begin()
{
    EEPROM.begin(512);
}

void StorageManager::saveVolume(int value)
{
    EEPROM.write(0,value);

    EEPROM.commit();
}

int StorageManager::loadVolume()
{
    return EEPROM.read(0);
}