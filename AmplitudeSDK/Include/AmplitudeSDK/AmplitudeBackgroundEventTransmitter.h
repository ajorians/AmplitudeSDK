#pragma once

#include "IAmplitudeBackgroundEventTransmitter.h"

#include <memory>

namespace AmplitudeSDK
{
   class AmplitudeBackgroundEventTransmitter : public IAmplitudeBackgroundEventTransmitter
   {
   public:
      AmplitudeBackgroundEventTransmitter( );
      ~AmplitudeBackgroundEventTransmitter();

      void Startup() override;

      void BeginShutdown() override;

      void Shutdown() override;

      void AddEvent(const AmplitudeEvent& amplitudeEvent) override;
   };
}
