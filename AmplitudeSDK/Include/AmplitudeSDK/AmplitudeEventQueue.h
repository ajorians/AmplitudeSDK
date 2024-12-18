#pragma once

#include "IAmplitudeEventQueue.h"

namespace AmplitudeSDK
{
   class AmplitudeEventQueue : public IAmplitudeEventQueue
   {
   public:
      AmplitudeEventQueue();

      void AddEventToQueue( const AmplitudeEvent& amplitudeEvent ) override;

      std::vector<AmplitudeEvent> GetEvents(int numRequestedEvents) override;

      void CompletedEvents(int numEventsCompleted) override;

      void PersistAllEvents() override;

   private:

   };
}
