#include <AmplitudeSDK/Amplitude.h>

#include <AmplitudeSDK/AmplitudeBackgroundEventTransmitter.h>
#include <AmplitudeSDK/AmplitudeEventFactory.h>
#include <AmplitudeSDK/AmplitudeEventQueue.h>
#include <AmplitudeSDK/AmplitudeExponentialBackoff.h>
#include <AmplitudeSDK/AmplitudeNetworkCalls.h>

#include <chrono>

using namespace AmplitudeSDK;
using namespace std::chrono_literals;

int main()
{
   auto amplitudeEventFactory = std::make_shared<AmplitudeEventFactory>();

   auto amplitudeNetworkCalls = std::make_shared<AmplitudeNetworkCalls>();
   auto amplitudeEventQueue = std::make_shared<AmplitudeEventQueue>( R"(C:\Users\a.orians\AppData\Local\TechSmith\Camtasia Studio)" );
   auto exponentialBackoff = std::make_shared<AmplitudeExponentialBackoff>();

   auto amplitudeBackgroundEventTransmitter = std::make_shared<AmplitudeBackgroundEventTransmitter>( amplitudeNetworkCalls, amplitudeEventQueue, exponentialBackoff );
   Amplitude amplitude(amplitudeEventFactory, amplitudeBackgroundEventTransmitter);

   amplitude.StartSession();
   amplitude.StopSession();
   std::this_thread::sleep_for(1s);
}
