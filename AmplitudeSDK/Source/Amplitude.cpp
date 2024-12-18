#include "AmplitudeSDK/Amplitude.h"

using namespace AmplitudeSDK;

Amplitude::Amplitude( std::shared_ptr<IAmplitudeEventFactory> amplitudeEventFactory,
                      std::shared_ptr<IAmplitudeBackgroundEventTransmitter> amplitudeBackgroundEventTransmitter )
   : _amplitudeEventFactory( std::move( amplitudeEventFactory ) )
   , _amplitudeBackgroundEventTransmitter( std::move( amplitudeBackgroundEventTransmitter ) )
{
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

}

void Amplitude::StopSession()
{

}

void Amplitude::Shutdown()
{

}

void Amplitude::TrackEventWithProperties(const std::string& eventName, const std::map<std::string, std::string>& properties)
{

}
