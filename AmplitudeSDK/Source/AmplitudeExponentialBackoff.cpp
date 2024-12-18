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
   return false;
}

void AmplitudeExponentialBackoff::IncrementFailure()
{

}

void AmplitudeExponentialBackoff::Reset()
{
   //_startTime = DateTime.Now;
   _retryCount = 0;
   _pow = 1;
   _currentDelay = 0s;
}
