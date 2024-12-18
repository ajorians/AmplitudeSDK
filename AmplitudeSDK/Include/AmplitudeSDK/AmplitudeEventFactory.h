#pragma once

#include "IAmplitudeEventFactory.h"

#include <memory>

namespace AmplitudeSDK
{
   class AmplitudeEventFactory : public IAmplitudeEventFactory
   {
   public:
      AmplitudeEvent CreateEventWithProperties( const std::string& eventName,
                                                const std::map<std::string, std::string>& eventProperties ) const override;
   };
}
