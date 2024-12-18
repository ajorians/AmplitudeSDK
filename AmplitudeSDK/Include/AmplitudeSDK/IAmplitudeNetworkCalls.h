#pragma once

#include <vector>

namespace AmplitudeSDK
{
   struct AmplitudeEvent;

   //Purpose: Do Network calls
   //Network rate-limiting ought to be done by another class.
   //Checking/Limiting number of items per network request ought to be done by another class
   //Validating event names are not greater than 1024 characters/whatever ought to be done by another class
   //Offline serializing/deserializing ought to be done by another class.
   //Offloading to a thread was intended to be in another class.  Though maybe async is OK?
   //This is intended that you can stop and start as many times as needed.
   //And you could have multiple instances of this class if need (though shouldn't need).
   class IAmplitudeNetworkCalls
   {
   public:
      virtual ~IAmplitudeNetworkCalls() = default;

      //Returns true is successful; false otherwise
      //Be sure to check Amplitude rate limits.  Requests per second/events per request.  And do exponential back-off is needed
      virtual bool PostEvents( const std::vector<AmplitudeEvent>& events ) = 0;
   };
}
