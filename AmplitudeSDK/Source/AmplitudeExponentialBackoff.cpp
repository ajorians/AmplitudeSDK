#include "AmplitudeSDK/AmplitudeExponentialBackoff.h"

using namespace std::chrono_literals;

namespace AmplitudeSDK
{
   std::chrono::milliseconds MaxDelayTime = 1h;
}

using namespace AmplitudeSDK;

AmplitudeExponentialBackoff::AmplitudeExponentialBackoff()
{
   Reset();
}

bool AmplitudeExponentialBackoff::HaveWaitedEnoughTime() const
{
   auto now = std::chrono::steady_clock::now();

   if (now >= _startTime + _currentDelay)
   {
      return true;
   }

   return false;
}

void AmplitudeExponentialBackoff::IncrementFailure()
{
   _retryCount++;
   if (_retryCount < 31)
   {
      _pow = _pow << 1;
   }

   std::chrono::milliseconds delay = 1s * _pow;
   _currentDelay = delay > MaxDelayTime ? MaxDelayTime : delay;
}

void AmplitudeExponentialBackoff::Reset()
{
   _startTime = std::chrono::steady_clock::now();
   _retryCount = 0;
   _pow = 1;
   _currentDelay = 0s;
}
