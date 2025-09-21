#include "StatusLEDChannel.h"

StatusLEDChannel::StatusLEDChannel(uint8_t index, uint8_t ledId)
{
    _led = openknx.leds.getLed(ledId);
    _channelIndex = index;
}

const std::string StatusLEDChannel::name()
{
    return "StatusLED";
}

void StatusLEDChannel::setup()
{
    if(ParamSLED_Mode_ == 1)
    { // LED-Funnction
        openknx.ledFunctions.AssignLed2Function(_led, ParamSLED_Func_);
    }
    else if(ParamSLED_Mode_ == 2)
    { // GO Control
        //ToDo:
        // check RGB Param vs _led->isRGB()

        logDebugP("Param Color Off %06X0", ParamSLED_ColorOff_);
        logDebugP("Param Color On %06X0", ParamSLED_ColorOn_);
        logDebugP("Param Color Prio1 %06X0", ParamSLED_ColorPrio1_);
        logDebugP("Param Color Prio2 %06X0", ParamSLED_ColorPrio2_);

        processSwitchInputKo();
    }
}

void StatusLEDChannel::loop()
{
    if(ParamSLED_Mode_ != 2)
        return;        

    
}
void StatusLEDChannel::processInputKo(GroupObject &ko)
{
    if(ParamSLED_Mode_ != 2)
        return;       

    uint16_t koNumber = ko.asap();
    int8_t koIndex = SLED_KoCalcIndex(koNumber);

    switch (koIndex)
    {
        case SLED_KoStatusLED_Switch_:
        case SLED_KoStatusLED_Prio1_:
        case SLED_KoStatusLED_Prio2_:
            processSwitchInputKo();
            break;
        case SLED_KoStatusLED_BrightnessColor_:
        case SLED_KoStatusLED_Effect_:
            processDetailedInputKo();
    }
}

void StatusLEDChannel::processSwitchInputKo()
{
    if(KoSLED_StatusLED_Prio2_.value(DPT_Switch))
    {
        // Prio2
        if(_led->isRGB())
        {
            ((OpenKNX::Led::RGB*)_led)->setColor(ParamSLED_ColorPrio2_);
        }
        else
        {
            _led->brightness(ParamSLED_BrightnessPrio2_);
        }
        switch (ParamSLED_EffectPrio2_)
        {
            case 0:
                _led->on();
                break;
            case 1:
                _led->blinking();
                break;
            case 2:
                _led->pulsing();
                break;
            default:
                _led->off();
        }
    }
    else if(KoSLED_StatusLED_Prio1_.value(DPT_Switch))
    {
        // Prio1
        if(_led->isRGB())
        {
            ((OpenKNX::Led::RGB*)_led)->setColor(ParamSLED_ColorPrio1_);
        }
        else
        {
            _led->brightness(ParamSLED_BrightnessPrio1_);
        }
        switch (ParamSLED_EffectPrio1_)
        {
            case 0:
                _led->on();
                break;
            case 1:
                _led->blinking();
                break;
            case 2:
                _led->pulsing();
                break;
            default:
                _led->off();
        }
    }
    else if(KoSLED_StatusLED_Switch_.value(DPT_Switch))
    {
        // On
        if(_led->isRGB())
        {
            if(ParamSLED_DetailedControl_ == 1) // Details KO Control mode 1
            {
                ((OpenKNX::Led::RGB*)_led)->setColor(KoSLED_StatusLED_BrightnessColor_.value(DPT_Colour_RGB));
            }
            else
            {
                ((OpenKNX::Led::RGB*)_led)->setColor(ParamSLED_ColorOn_);
            }
        }
        else
        {
            if(ParamSLED_DetailedControl_ == 1) // Details KO Control mode 1
            {
                _led->brightness(KoSLED_StatusLED_BrightnessColor_.value(DPT_Scaling));
            }
            else
            {
                _led->brightness(ParamSLED_BrightnessOn_);
            }
        }
        switch (ParamSLED_EffectOn_)
        {
            case 0:
                _led->on();
                break;
            case 1:
                _led->blinking();
                break;
            case 2:
                _led->pulsing();
                break;
            default:
                _led->off();
        }
    }
    else
    {
        // Off
        if(_led->isRGB())
        {
            ((OpenKNX::Led::RGB*)_led)->setColor(ParamSLED_ColorOff_);
        }
        else
        {
            _led->brightness(ParamSLED_BrightnessOff_);
        }
        switch (ParamSLED_EffectOff_)
        {
            case 0:
                _led->on();
                break;
            case 1:
                _led->blinking();
                break;
            case 2:
                _led->pulsing();
                break;
            default:
                _led->off();
        }
    }
}

void StatusLEDChannel::processDetailedInputKo()
{
    if(ParamSLED_DetailedControl_ == 1)
    {
        processSwitchInputKo();
    }
    else if(ParamSLED_DetailedControl_ == 3)
    {
        if(_led->isRGB())
        {
            ((OpenKNX::Led::RGB*)_led)->setColor(KoSLED_StatusLED_BrightnessColor_.value(DPT_Colour_RGB));
        }
        else
        {
            _led->brightness(KoSLED_StatusLED_BrightnessColor_.value(DPT_Scaling));
        }
        switch ((uint32_t)KoSLED_StatusLED_Effect_.value(DPT_Value_4_Ucount))
        {
            case 0:
                _led->on();
                break;
            case 1:
                _led->blinking();
                break;
            case 2:
                _led->pulsing();
                break;
            default:
                _led->off();
        }
    }
    
    

}