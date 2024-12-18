#pragma once

#include "IAmplitudeBackgroundEventTransmitter.h"

#include <memory>
#include <thread>

namespace AmplitudeSDK
{
   class IAmplitudeEventQueue;
   class IAmplitudeExponentialBackoff;
   class IAmplitudeNetworkCalls;

   class AmplitudeBackgroundEventTransmitter : public IAmplitudeBackgroundEventTransmitter
   {
   public:
      AmplitudeBackgroundEventTransmitter( std::shared_ptr<IAmplitudeNetworkCalls> amplitudeNetworkCalls,
                                           std::shared_ptr<IAmplitudeEventQueue> amplitudeEventQueue,
                                           std::shared_ptr<IAmplitudeExponentialBackoff> exponentialBackoff );
      ~AmplitudeBackgroundEventTransmitter();

      void Startup() override;

      void BeginShutdown() override;

      void Shutdown() override;

      void AddEvent(const AmplitudeEvent& amplitudeEvent) override;

   private:
      void DoAnalytics();

   private:
      std::shared_ptr<IAmplitudeNetworkCalls> _amplitudeNetworkCalls;
      std::shared_ptr<IAmplitudeEventQueue> _amplitudeEventQueue;
      std::shared_ptr<IAmplitudeExponentialBackoff> _exponentialBackoff;

      std::thread _workerThread;
      bool _keepRunning = false;
      bool _beginShutdown = false;
   };
}
