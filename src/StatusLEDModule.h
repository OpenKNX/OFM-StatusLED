#include "StatusLEDChannel.h"
#include "hardware.h"

class StatusLEDModule : public OpenKNX::Module
{

  public:
    void loop() override;
    void setup() override;
    void processAfterStartupDelay() override;
    void processInputKo(GroupObject& ko) override;

    const std::string name() override;
    const std::string version() override;
    // void writeFlash() override;
    // void readFlash(const uint8_t* data, const uint16_t size) override;
    // uint16_t flashSize() override;

  private:
    uint8_t _currentChannel = 0;
    StatusLEDChannel* _channels[SLED_ChannelCount];
};

extern StatusLEDModule openknxStatusLEDModule;