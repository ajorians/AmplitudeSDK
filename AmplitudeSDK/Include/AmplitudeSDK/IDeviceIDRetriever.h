#pragma once

#include <string>

namespace AmplitudeSDK
{
   class IDeviceIDRetriever
   {
   public:
      virtual ~IDeviceIDRetriever() = default;

      //Get the device ID.
      //Should be a persisted unique value that is shared across versions of the product
      virtual std::string GetDeviceID() const = 0;
   };
}
