#pragma once

#include "IAmplitudeEventFactory.h"

#include <memory>

namespace AmplitudeSDK
{
   class IUserIDRetriever;
   class IDeviceIDRetriever;
   class IUserPropertiesRetriever;

   class AmplitudeEventFactory : public IAmplitudeEventFactory
   {
   public:
      AmplitudeEventFactory( std::shared_ptr<IUserIDRetriever> userIDRetriever,
                             std::shared_ptr<IDeviceIDRetriever> deviceIDRetriever,
                             std::shared_ptr<IUserPropertiesRetriever> userPropertiesRetriever );

      ~AmplitudeEventFactory();

      AmplitudeEvent CreateEventWithProperties( const std::string& eventName,
                                                const std::map<std::string, std::string>& eventProperties ) const override;

   private:
      std::shared_ptr<IUserIDRetriever> _userIDRetriever;
      std::shared_ptr<IDeviceIDRetriever> _deviceIDRetriever;
      std::shared_ptr<IUserPropertiesRetriever> _userPropertiesRetriever;
   };
}
