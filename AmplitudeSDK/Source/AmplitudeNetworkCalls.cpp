#include "AmplitudeSDK/AmplitudeNetworkCalls.h"

#include "AmplitudeSDK/AmplitudeEvent.h"

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"

namespace AmplitudeSDK
{
   constexpr const char* EndPoint = "https://api2.amplitude.com";

   class AmplitudeNetworkCallsImpl
   {
   public:
      AmplitudeNetworkCallsImpl()
         : _httpClient(EndPoint)
      {

      }

      bool PostEvents(const std::vector<AmplitudeEvent>& events)
      {
         /*auto res = _httpClient.Post("/2/httpapi", json, "application/json");
         res->status;
         res->body;*/
         return false;
      }

   private:
      httplib::Client _httpClient;
   };
}

using namespace AmplitudeSDK;

AmplitudeNetworkCalls::AmplitudeNetworkCalls()
   : _impl( std::make_unique<AmplitudeNetworkCallsImpl>() )
{
}

AmplitudeNetworkCalls::~AmplitudeNetworkCalls()
{
}

bool AmplitudeNetworkCalls::PostEvents( const std::vector<AmplitudeEvent>& events )
{
   return _impl->PostEvents( events );
}
