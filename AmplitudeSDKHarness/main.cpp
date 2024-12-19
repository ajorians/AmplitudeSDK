#include <AmplitudeSDK/Amplitude.h>

#include <AmplitudeSDK/AmplitudeBackgroundEventTransmitter.h>
#include <AmplitudeSDK/AmplitudeEventFactory.h>
#include <AmplitudeSDK/AmplitudeEventQueue.h>
#include <AmplitudeSDK/AmplitudeExponentialBackoff.h>
#include <AmplitudeSDK/AmplitudeNetworkCalls.h>
#include <AmplitudeSDK/IDeviceIDRetriever.h>
#include <AmplitudeSDK/IUserIDRetriever.h>
#include <AmplitudeSDK/IUserPropertiesRetriever.h>

#include <chrono>
#include <map>
#include <string>

using namespace AmplitudeSDK;
using namespace std::chrono_literals;

namespace
{
   class DeviceIDRetriever : public IDeviceIDRetriever
   {
   public:
      std::string GetDeviceID() const
      {
         return "Device ID here";
      }
   };

   class UserIDRetriever : public IUserIDRetriever
   {
   public:
      std::string GetUserID() const
      {
         return "";
      }
   };

   class UserPropertiesRetriever : public IUserPropertiesRetriever
   {
   public:
      std::map<std::string, std::string> GetUserProperties() const
      {
         return {};
      }
   };
}

int main()
{
   auto deviceIDRetriver = std::make_shared<DeviceIDRetriever>();
   auto userIDRetriver = std::make_shared<UserIDRetriever>();
   auto userPropertiesRetriver = std::make_shared<UserPropertiesRetriever>();
   auto amplitudeEventFactory = std::make_shared<AmplitudeEventFactory>( userIDRetriver, deviceIDRetriver, userPropertiesRetriver );

   auto amplitudeNetworkCalls = std::make_shared<AmplitudeNetworkCalls>();
   auto amplitudeEventQueue = std::make_shared<AmplitudeEventQueue>( R"(C:\Users\a.orians\AppData\Local\TechSmith\Camtasia Studio)" );
   auto exponentialBackoff = std::make_shared<AmplitudeExponentialBackoff>();

   auto amplitudeBackgroundEventTransmitter = std::make_shared<AmplitudeBackgroundEventTransmitter>( amplitudeNetworkCalls, amplitudeEventQueue, exponentialBackoff );
   Amplitude amplitude(amplitudeEventFactory, amplitudeBackgroundEventTransmitter);

   amplitude.StartSession();
   amplitude.StopSession();
   std::this_thread::sleep_for(1s);
}
