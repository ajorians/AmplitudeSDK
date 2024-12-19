#include "AmplitudeSDK/AmplitudeBackgroundEventTransmitter.h"

#include "AmplitudeSDK/AmplitudeEvent.h"
#include "AmplitudeSDK/IAmplitudeEventQueue.h"
#include "AmplitudeSDK/IAmplitudeExponentialBackoff.h"
#include "AmplitudeSDK/IAmplitudeNetworkCalls.h"

#include <cassert>
#include <limits>
#include <vector>

using namespace AmplitudeSDK;
using namespace std::chrono_literals;

AmplitudeBackgroundEventTransmitter::AmplitudeBackgroundEventTransmitter( std::shared_ptr<IAmplitudeNetworkCalls> amplitudeNetworkCalls,
                                                                          std::shared_ptr<IAmplitudeEventQueue> amplitudeEventQueue,
                                                                          std::shared_ptr<IAmplitudeExponentialBackoff> exponentialBackoff )
   : _amplitudeNetworkCalls( std::move( amplitudeNetworkCalls ) )
   , _amplitudeEventQueue( std::move( amplitudeEventQueue ) )
   , _exponentialBackoff( std::move( exponentialBackoff ) )
{

}

AmplitudeBackgroundEventTransmitter::~AmplitudeBackgroundEventTransmitter()
{
   Shutdown();
}

void AmplitudeBackgroundEventTransmitter::Startup()
{
   if (_workerThread.joinable())
   {
      //You must have already called startup.  You can Shutdown and Startup again; but I probably would make a new instance each time.
      assert(false);
      return;
   }

   _beginShutdown = false;
   _keepRunning = true;
   _workerThread = std::thread([this]() { DoAnalytics(); } );
}

void AmplitudeBackgroundEventTransmitter::BeginShutdown()
{
   _beginShutdown = true;
}

void AmplitudeBackgroundEventTransmitter::Shutdown()
{
   _keepRunning = false;
   if ( _workerThread.joinable() )
   {
      _workerThread.join();
   }

   //Tell event queue to pack up all pending events to a file
   _amplitudeEventQueue->PersistAllEvents();
}

void AmplitudeBackgroundEventTransmitter::AddEvent( const AmplitudeEvent& amplitudeEvent )
{
   if (_beginShutdown)
   {
      //We call BeginShutdown() on application closing.  There shouldn't be any more user events as the application is closing.
      //But say there was.  It gets discarded.  If it wasn't it would get sent after the sesson_end event.
#ifdef _WIN32
      assert(false); //Just to let you know your event was not added
#endif
      return;
   }

   _amplitudeEventQueue->AddEventToQueue(amplitudeEvent);
}

void AmplitudeBackgroundEventTransmitter::DoAnalytics()
{
   while (_keepRunning)
   {
      //I put the sleep as the first thing in the loop so after session_end the hope is we'll transmit it before joining the thread.
      //Of course this isn't guaranteed (especially if we reduce the sleep time or if there is a lot of events going through)
      std::this_thread::sleep_for(1'000ms);

      if (!_exponentialBackoff->HaveWaitedEnoughTime())
      {
         continue;
      }

      //Ask the rate limiter for how many events we can handle for this request.  TODO: Add a rate limiter
      int numEventsCanHandle = std::numeric_limits<int>::max();

      //Now get some work, if any, to do
      std::vector<AmplitudeEvent> eventsToProcess = _amplitudeEventQueue->GetEvents(numEventsCanHandle);

      if (!eventsToProcess.empty())
      {
         if (_amplitudeNetworkCalls->PostEvents(eventsToProcess))
         {
            int numEventsCompleted = static_cast<int>( eventsToProcess.size() );
            _amplitudeEventQueue->CompletedEvents(numEventsCompleted);
            _exponentialBackoff->Reset();
         }
         else
         {
            //Exponential back off.  If offline/server issues I'd hate to try again every second
            _exponentialBackoff->IncrementFailure();
         }
      }
   }
}
