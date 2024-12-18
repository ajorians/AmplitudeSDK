#pragma once

namespace AmplitudeSDK
{
   struct AmplitudeEvent;

   class IAmplitudeBackgroundEventTransmitter
   {
   public:
      virtual ~IAmplitudeBackgroundEventTransmitter() = default;

      //Starts the background thread
      virtual void Startup() = 0;

      //On application close you need to close quicker; but you also want to transmit session end.
      //This stops any additional events from being added (which you are shutting down; there shouldn't be any)
      virtual void BeginShutdown() = 0;

      //This Joins the background thread
      virtual void Shutdown() = 0;

      //This adds the event to a queue that will get processed (potentially serialized)
      virtual void AddEvent( const AmplitudeEvent& amplitudeEvent ) = 0;
   };
}
