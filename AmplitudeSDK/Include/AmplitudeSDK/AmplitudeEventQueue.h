#pragma once

#include "IAmplitudeEventQueue.h"

#include "AmplitudeEvent.h"

#include <deque>
#include <mutex>
#include <string>

namespace AmplitudeSDK
{
   struct AmplitudeEvent;

   class AmplitudeEventQueue : public IAmplitudeEventQueue
   {
   public:
      AmplitudeEventQueue( const std::string& persistEventPath);

      void AddEventToQueue( const AmplitudeEvent& amplitudeEvent ) override;

      std::vector<AmplitudeEvent> GetEvents(int numRequestedEvents) override;

      void CompletedEvents(int numEventsCompleted) override;

      void PersistAllEvents() override;

   private:
      void CheckFiles();

   private:
      std::deque<AmplitudeEvent> _pendingEvents;
      std::mutex _lockPendingEvents;

      //This is the root path.  To make sure it doesn't grow infinitely; each days event are a separate file
      //I suppose may be empty if you are OK with offline events disappearing
      std::string _persistEventPath;

      bool _isUsingSerializedEvents = false;
      std::deque<AmplitudeEvent> _serializedEvents;
      std::string _serializedFilename;
   };
}
