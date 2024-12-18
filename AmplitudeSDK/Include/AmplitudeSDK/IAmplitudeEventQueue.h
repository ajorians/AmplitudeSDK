#pragma once

#include <vector>

namespace AmplitudeSDK
{
   struct AmplitudeEvent;

   class IAmplitudeEventQueue
   {
   public:
      virtual ~IAmplitudeEventQueue() = default;

      //Adds the event to the bottom of the queue
      virtual void AddEventToQueue( const AmplitudeEvent& amplitudeEvent ) = 0;

      //Gets the request number of top-most events from the queue
      //Can only provide what it has; might get less that requested
      virtual std::vector<AmplitudeEvent> GetEvents( int numRequestedEvents ) = 0;

      //Removes the indicated number of now completed events from the top of the queue
      virtual void CompletedEvents( int numEventsCompleted ) = 0;

      //Instructs to write out all events and clear it's entire queue
      virtual void PersistAllEvents() = 0;
   };
}
