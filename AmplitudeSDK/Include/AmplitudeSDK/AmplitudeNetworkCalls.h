#pragma once

#include "IAmplitudeNetworkCalls.h"

#include <memory>

namespace AmplitudeSDK
{
   class AmplitudeNetworkCallsImpl;

   class AmplitudeNetworkCalls : public IAmplitudeNetworkCalls
   {
   public:
      AmplitudeNetworkCalls();
      ~AmplitudeNetworkCalls();

      bool PostEvents(const std::vector<AmplitudeEvent>& events) override;

   private:
      std::unique_ptr<AmplitudeNetworkCallsImpl> _impl;
   };
}
