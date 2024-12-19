#pragma once

#include <map>
#include <string>

namespace AmplitudeSDK
{
   class IUserPropertiesRetriever
   {
   public:
      virtual ~IUserPropertiesRetriever() = default;

      //Get the user properties.
      virtual std::map<std::string, std::string> GetUserProperties() const = 0;
   };
}
