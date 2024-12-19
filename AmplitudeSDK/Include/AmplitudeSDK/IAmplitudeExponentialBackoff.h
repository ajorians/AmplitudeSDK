#pragma once

namespace AmplitudeSDK
{
   struct AmplitudeEvent;

   class IAmplitudeExponentialBackoff
   {
   public:
      virtual ~IAmplitudeExponentialBackoff() = default;

      //OK to post network message
      virtual bool HaveWaitedEnoughTime() const = 0;

      //Call this when have a network failure
      virtual void IncrementFailure() = 0;

      //Call this upon successful network transmission
      virtual void Reset() = 0;
   };
}
