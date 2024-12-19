#pragma once

#include <chrono>
#include <map>
#include <string>

namespace AmplitudeSDK
{
   //The easiest way to get one of these is to use the AmplitudeEventFactory
   struct AmplitudeEvent
   {
      std::string InsertID;
      std::string UserID;
      std::string DeviceID;
      std::string EventType;
      std::map<std::string, std::string> EventProperties;
      std::map<std::string, std::string> UserProperties;
      std::string Platform;
      std::string OS;
      std::string OSVersion;
      std::string Language;
      std::chrono::time_point<std::chrono::system_clock> Time;
   };
}
