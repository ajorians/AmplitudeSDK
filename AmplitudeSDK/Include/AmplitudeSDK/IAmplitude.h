#pragma once

#include <map>
#include <string>

namespace AmplitudeSDK
{
   class IAmplitude
   {
   public:
      virtual ~IAmplitude() = default;

      //Emitted when tracked an event.  Unrelated to network call occurred or if successfully tracked (could have been persisted)
      //Note session_start and session_end are "events".
      virtual void Attach() = 0;
      virtual void Detach() = 0;

      //Call this right after instantiation
      virtual void StartSession() = 0;

      //Call this as soon as you know you are closing the application
      virtual void StopSession() = 0;

      //Call this as late as you can while closing as this shuts the whole thing down
      virtual void Shutdown() = 0;

      //void return on purpose.  You assume it'll be successfully tracked.
      virtual void TrackEventWithProperties( const std::string& eventName, const std::map<std::string, std::string>& properties) = 0;
   };
}
