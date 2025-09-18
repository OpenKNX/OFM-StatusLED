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
        _led->on();
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
        _led->on();
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
        _led->on();
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
        _led->on();
    }
}