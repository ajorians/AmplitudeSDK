#pragma once

#include <string>

namespace AmplitudeSDK
{
   class IUserIDRetriever
   {
   public:
      virtual ~IUserIDRetriever() = default;

      //Get the user ID.
      //Should be your TSC ID or empty until you have it
      virtual std::string GetUserID() const = 0;
   };
}
