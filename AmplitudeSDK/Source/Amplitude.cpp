#include "AmplitudeSDK/Amplitude.h"

#include "AmplitudeSDK/AmplitudeEvent.h"
#include "AmplitudeSDK/IAmplitudeBackgroundEventTransmitter.h"
#include "AmplitudeSDK/IAmplitudeEventFactory.h"

using namespace AmplitudeSDK;

Amplitude::Amplitude( std::shared_ptr<IAmplitudeEventFactory> amplitudeEventFactory,
                      std::shared_ptr<IAmplitudeBackgroundEventTransmitter> amplitudeBackgroundEventTransmitter )
   : _amplitudeEventFactory( std::move( amplitudeEventFactory ) )
   , _amplitudeBackgroundEventTransmitter( std::move( amplitudeBackgroundEventTransmitter ) )
{
   _amplitudeBackgroundEventTransmitter->Startup();
}

Amplitude::~Amplitude()
{

}

void Amplitude::Attach()
{

}

void Amplitude::Detach()
{

}

void Amplitude::StartSession()
{
   const std::string eventName = "session_start";
   std::map<std::string, std::string> eventProperties;

   //Add this event to something that is responsible for handling it on the background such that this function can quickly return
   _amplitudeBackgroundEventTransmitter->AddEvent(_amplitudeEventFactory->CreateEventWithProperties(eventName, eventProperties));

   //OnTrackedEvent ? .Invoke(this, new(){ EventName = eventName, EventProperties = eventProperties });
}

void Amplitude::StopSession()
{
   const std::string eventName = "session_end";
   std::map<std::string, std::string> eventProperties;

   //Add this event to something that is responsible for handling it on the background such that this function can quickly return
   _amplitudeBackgroundEventTransmitter->AddEvent(_amplitudeEventFactory->CreateEventWithProperties(eventName, eventProperties));

   //OnTrackedEvent ? .Invoke(this, new(){ EventName = eventName, EventProperties = eventProperties });

   _amplitudeBackgroundEventTransmitter->BeginShutdown();
}

void Amplitude::Shutdown()
{
   _amplitudeBackgroundEventTransmitter->Shutdown();
}

void Amplitude::TrackEventWithProperties(const std::string& eventName, const std::map<std::string, std::string>& eventProperties)
{
   //Add this event to something that is responsible for handling it on the background such that this function can quickly return
   _amplitudeBackgroundEventTransmitter->AddEvent(_amplitudeEventFactory->CreateEventWithProperties(eventName, eventProperties));

   //OnTrackedEvent ? .Invoke(this, new(){ EventName = eventName, EventProperties = eventProperties });
}
