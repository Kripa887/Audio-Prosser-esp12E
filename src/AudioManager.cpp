#include "AudioManager.h"

void AudioManager::begin()
{
    Wire.begin();

    apply();
}

void AudioManager::update()
{
}

void AudioManager::apply()
{
    tda.setInput(input);

    tda.inputGain(gain);

    tda.setVolume(volume);

    tda.setSnd(bass,1);
    tda.setSnd(mids,2);
    tda.setSnd(treble,3);

    tda.spkAtt(4-balance,4+balance);
}