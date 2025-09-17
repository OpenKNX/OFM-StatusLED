#include "StatusLEDChannel.h"

StatusLEDChannel::StatusLEDChannel(uint8_t index)
{
    _channelIndex = index;
}

const std::string StatusLEDChannel::name()
{
    return "StatusLED";
}

void StatusLEDChannel::setup()
{
    

    // Debug
    // logInfoP("_buttonParams[0].inputKo: %i", _buttonParams[0].inputKo);
    // logInfoP("_buttonParams[1].inputKo: %i", _buttonParams[1].inputKo);
    // logInfoP("_buttonParams[0].outputShortPressActive: %i", _buttonParams[0].outputShortPressActive);
    // logInfoP("_buttonParams[0].outputShortReleaseActive: %i", _buttonParams[0].outputShortReleaseActive);
    // logInfoP("_buttonParams[0].outputLongPressActive: %i", _buttonParams[0].outputLongPressActive);
    // logInfoP("_buttonParams[0].outputLongReleaseActive: %i", _buttonParams[0].outputLongReleaseActive);
    // logInfoP("_buttonParams[0].outputShortRelease: %i", _buttonParams[0].outputShortRelease);
    // logInfoP("_buttonParams[0].outputLongPress: %i", _buttonParams[0].outputLongPress);
    // logInfoP("_buttonParams[0].outputLongRelease: %i", _buttonParams[0].outputLongRelease);
    // logInfoP("ParamSLED_bStatusFallbackTime: %i", ParamSLED_bStatusFallbackTime * 1000);
    // logInfoP("ParamSLED_bStatusThresholdHigh: %i", ParamSLED_bStatusThresholdHigh);
    // logInfoP("ParamSLED_bStatusThresholdLow: %i", ParamSLED_bStatusThresholdLow);
}

void StatusLEDChannel::loop()
{

}
void StatusLEDChannel::processInputKo(GroupObject &ko)
{
    if(ParamSLED_Mode_ == 0 || _led == nullptr)
        return;

    uint16_t koNumber = ko.asap();
    int8_t koIndex = SLED_KoCalcIndex(koNumber);

    switch (koIndex)
    {
        case SLED_KoStatusLED_Switch_:
            _led->on(ko.value(DPT_Switch));
            break;
    }
}