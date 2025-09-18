#pragma once
#include "OpenKNX.h"

class StatusLEDChannel : public OpenKNX::Channel
{

  private:
    OpenKNX::Led::Base* _led = nullptr;
    uint16_t _ledNumber = 0;
    void processSwitchInputKo();

  public:
    StatusLEDChannel(uint8_t index, uint8_t ledId);

    void setup() override;
    void loop() override;
    void processInputKo(GroupObject &ko) override;

    const std::string name() override;
};