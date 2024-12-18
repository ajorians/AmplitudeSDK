#pragma once

#include "IAmplitude.h"

#include <memory>

namespace AmplitudeSDK
{
   class IAmplitudeBackgroundEventTransmitter;
   class IAmplitudeEventFactory;

   class Amplitude : public IAmplitude
   {
   public:
      Amplitude( std::shared_ptr<IAmplitudeEventFactory> amplitudeEventFactory,
                 std::shared_ptr<IAmplitudeBackgroundEventTransmitter> amplitudeBackgroundEventTransmitter );
      ~Amplitude();

      void Attach() override;//TODO
      void Detach() override;

      void StartSession() override;

      void StopSession() override;

      void Shutdown() override;

      void TrackEventWithProperties(const std::string& eventName, const std::map<std::string, std::string>& properties) override;

   private:
      std::shared_ptr<IAmplitudeEventFactory> _amplitudeEventFactory;
      std::shared_ptr<IAmplitudeBackgroundEventTransmitter> _amplitudeBackgroundEventTransmitter;
   };
}
