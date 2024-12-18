#include <AmplitudeSDK/Amplitude.h>

#include <AmplitudeSDK/AmplitudeBackgroundEventTransmitter.h>
#include <AmplitudeSDK/AmplitudeEventFactory.h>
#include <AmplitudeSDK/AmplitudeEventQueue.h>
#include <AmplitudeSDK/AmplitudeExponentialBackoff.h>
#include <AmplitudeSDK/AmplitudeNetworkCalls.h>

using namespace AmplitudeSDK;

int main()
{
   auto amplitudeEventFactory = std::make_shared<AmplitudeEventFactory>();

   auto amplitudeNetworkCalls = std::make_shared<AmplitudeNetworkCalls>();
   auto amplitudeEventQueue = std::make_shared<AmplitudeEventQueue>();
   auto exponentialBackoff = std::make_shared<AmplitudeExponentialBackoff>();

   auto amplitudeBackgroundEventTransmitter = std::make_shared<AmplitudeBackgroundEventTransmitter>( amplitudeNetworkCalls, amplitudeEventQueue, exponentialBackoff );
   Amplitude amplitude(amplitudeEventFactory, amplitudeBackgroundEventTransmitter);
}
