#include "AmplitudeSDK/AmplitudeEventFactory.h"

#include "AmplitudeSDK/AmplitudeEvent.h"

#include <chrono>

using namespace AmplitudeSDK;

AmplitudeEvent AmplitudeEventFactory::CreateEventWithProperties( const std::string& eventName,
                                                                 const std::map<std::string, std::string>& eventProperties ) const
{
   //TODO: Check eventName to make sure it isn't empty or to long

   AmplitudeEvent result;

   result.InsertID = "Create Guid HERE";
   result.UserID = "Put UserID HERE";
   result.DeviceID = "Put DeviceID HERE";
   result.EventType = eventName;
   result.EventProperties = {};
   result.UserProperties = {};
   result.Platform = "Put Platform HERE";
   result.OS = "Put OS HERE";
   result.OSVersion = "Put OSVersion HERE";
   result.Language = "Put Language HERE";
   result.Time = std::chrono::system_clock::now();

   return result;
}
