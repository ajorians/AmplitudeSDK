#include <AmplitudeSDK/Amplitude.h>
#include <AmplitudeSDK/AmplitudeEventFactory.h>
#include <AmplitudeSDK/AmplitudeBackgroundEventTransmitter.h>

using namespace AmplitudeSDK;

int main()
{
   auto amplitudeEventFactory = std::make_shared<AmplitudeEventFactory>();
   auto amplitudeBackgroundEventTransmitter = std::make_shared<AmplitudeBackgroundEventTransmitter>();
   Amplitude amplitude(amplitudeEventFactory, amplitudeBackgroundEventTransmitter);
}
