#include "AmplitudeSDK/AmplitudeEventQueue.h"

#include "AmplitudeSDK/AmplitudeEvent.h"

using namespace AmplitudeSDK;

AmplitudeEventQueue::AmplitudeEventQueue()
{

}

void AmplitudeEventQueue::AddEventToQueue(const AmplitudeEvent& amplitudeEvent)
{

}

std::vector<AmplitudeEvent> AmplitudeEventQueue::GetEvents(int numRequestedEvents)
{
   return {};
}

void AmplitudeEventQueue::CompletedEvents(int numEventsCompleted)
{
   //Check that queue has at least numEventsCompleted events
}

void AmplitudeEventQueue::PersistAllEvents()
{

}
