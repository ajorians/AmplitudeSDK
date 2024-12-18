#pragma once

#include "IAmplitudeExponentialBackoff.h"

#include <chrono>

namespace AmplitudeSDK
{
   class AmplitudeExponentialBackoff : public IAmplitudeExponentialBackoff
   {
   public:
      AmplitudeExponentialBackoff();

      bool HaveWaitedEnoughTime() const override;
      void IncrementFailure() override;
      void Reset() override;

   private:
      /*DateTime _startTime;*/
      int _retryCount = 0;
      int _pow = 1;
      std::chrono::milliseconds _currentDelay;
   };
}
