#include "StatusLEDModule.h"
#include "ModuleVersionCheck.h"

const std::string StatusLEDModule::name()
{
    return "StatusLED";
}

const std::string StatusLEDModule::version()
{
    return MODULE_StatusLED_Version;
}

int StatusLEDModule::channelCount() {
#ifndef OPENKNX_SLED_IDs
    return 0;
#else
    return MIN(ParamSLED_VisibleChannels, OPENKNX_SLED_COUNT);
#endif
}

void StatusLEDModule::setup()
{
    for (uint8_t i = 0; i < channelCount(); i++)
    {
        _channels[i] = new StatusLEDChannel(i, _ledIds[i]);
        _channels[i]->setup();
    }
}

void StatusLEDModule::loop()
{
    if (channelCount() == 0) return;

    uint8_t processed = 0;
    do
        _channels[_currentChannel]->loop();
    while (openknx.freeLoopIterate(channelCount(), _currentChannel, processed));
}

void StatusLEDModule::processInputKo(GroupObject& iKo)
{
    for (uint8_t i = 0; i < channelCount(); i++)
        _channels[i]->processInputKo(iKo);
}

StatusLEDModule openknxStatusLEDModule;