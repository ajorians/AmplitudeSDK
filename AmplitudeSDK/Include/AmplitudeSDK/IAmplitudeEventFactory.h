#pragma once

#include <map>
#include <string>

namespace AmplitudeSDK
{
   struct AmplitudeEvent;

   class IAmplitudeEventFactory
   {
   public:
      virtual ~IAmplitudeEventFactory() = default;

      virtual AmplitudeEvent CreateEventWithProperties( const std::string& eventName,
                                                        const std::map<std::string, std::string>& eventProperties ) const = 0;
   };
}
