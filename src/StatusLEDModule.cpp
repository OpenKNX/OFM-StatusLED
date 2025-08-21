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

void StatusLEDModule::setup()
{
    for (uint8_t i = 0; i < ParamSLED_VisibleChannels; i++)
    {
        _channels[i] = new StatusLEDChannel(i);
        _channels[i]->setup();
    }
}

void StatusLEDModule::loop()
{
    if (ParamSLED_VisibleChannels == 0) return;

    uint8_t processed = 0;
    do
        _channels[_currentChannel]->loop();
    while (openknx.freeLoopIterate(ParamSLED_VisibleChannels, _currentChannel, processed));
}

void StatusLEDModule::processInputKo(GroupObject& iKo)
{
    for (uint8_t i = 0; i < ParamSLED_VisibleChannels; i++)
        _channels[i]->processInputKo(iKo);
}

StatusLEDModule openknxStatusLEDModule;