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
    /*
    if (ParamSLED_bMode == 0)
        return;

    uint16_t koNumber = ko.asap();
    int8_t koIndex = SLED_KoCalcIndex(koNumber);
    // logInfoP("koNumber %i -> koIndex %i", koNumber, koIndex);

    // External KO -> to Channel Mapping
    if (_buttonParams[0].inputKo > 0 && _buttonParams[0].inputKo == koNumber)
    {
        koIndex = SLED_KoIn1;
    }
    else if (_buttonParams[1].inputKo > 0 && _buttonParams[1].inputKo == koNumber)
    {
        koIndex = SLED_KoIn2;
    }

    switch (koIndex)
    {
        case SLED_KoIn1:
            processInputKoInput(ko, 0);
            break;
        case SLED_KoIn2:
            processInputKoInput(ko, 1);
            break;
        case SLED_KoLock:
            processInputKoLock(ko);
            break;
        case SLED_KoOut1Status:
            processInputKoStatus(ko, 1, ParamSLED_bOutShort_DPT, _statusShort);
            break;
        case SLED_KoOut2Status:
            processInputKoStatus(ko, 2, ParamSLED_bOutLong_DPT, _statusLong);
            break;
        case SLED_KoOut3Status:
            processInputKoStatus(ko, 3, ParamSLED_bOutExtraLong_DPT, _statusExtraLong);
            break;
    }
    */
}