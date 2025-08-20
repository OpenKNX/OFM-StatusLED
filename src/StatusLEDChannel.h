#pragma once
#include "OpenKNX.h"

class StatusLEDChannel : public OpenKNX::Channel
{

  private:


  public:
    StatusLEDChannel(uint8_t index);

    void setup() override;
    void loop() override;
    void processInputKo(GroupObject &ko) override;
    const std::string name() override;
};