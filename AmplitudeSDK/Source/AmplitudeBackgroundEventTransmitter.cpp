#include "AmplitudeSDK/AmplitudeBackgroundEventTransmitter.h"

using namespace AmplitudeSDK;

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

}

void AmplitudeBackgroundEventTransmitter::Startup()
{

}

void AmplitudeBackgroundEventTransmitter::BeginShutdown()
{

}

void AmplitudeBackgroundEventTransmitter::Shutdown()
{

}

void AmplitudeBackgroundEventTransmitter::AddEvent( const AmplitudeEvent& amplitudeEvent )
{

}
