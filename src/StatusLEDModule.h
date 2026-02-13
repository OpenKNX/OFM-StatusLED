#include "StatusLEDChannel.h"
#include "hardware.h"

class StatusLEDModule : public OpenKNX::Module
{

  public:
    void loop() override;
    void setup() override;
    void processInputKo(GroupObject& ko) override;
    int channelCount();

    const std::string name() override;
    const std::string version() override;

  private:
    uint8_t _currentChannel = 0;
#ifdef OPENKNX_SLED_IDs
    uint8_t _ledIds[SLED_ChannelCount] = {OPENKNX_SLED_IDs};
#else
    uint8_t _ledIds[SLED_ChannelCount] = {0};
#endif
    StatusLEDChannel* _channels[SLED_ChannelCount];
};

extern StatusLEDModule openknxStatusLEDModule;