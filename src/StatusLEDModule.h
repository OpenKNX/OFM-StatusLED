#include "StatusLEDChannel.h"
#include "hardware.h"

class StatusLEDModule : public OpenKNX::Module
{

  public:
    void loop() override;
    void setup() override;
    void processInputKo(GroupObject& ko) override;

    const std::string name() override;
    const std::string version() override;

  private:
    uint8_t _currentChannel = 0;
    uint8_t _ledIds[SLED_ChannelCount] = {OPENKNX_SLED_IDs};
    StatusLEDChannel* _channels[SLED_ChannelCount];
};

extern StatusLEDModule openknxStatusLEDModule;