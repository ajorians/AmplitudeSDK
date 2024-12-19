#include "AmplitudeSDK/AmplitudeEventFactory.h"

#include "AmplitudeSDK/AmplitudeEvent.h"
#include "AmplitudeSDK/IDeviceIDRetriever.h"
#include "AmplitudeSDK/IUserIDRetriever.h"
#include "AmplitudeSDK/IUserPropertiesRetriever.h"

#ifdef _WIN32
#include <windows.h>
#include <combaseapi.h>
#endif

#include <chrono>
#include <exception>
#include <string>
#include <string_view>

namespace
{
   std::string ToStdString(std::wstring_view wstr)
   {
      std::string str;
      int nchars = ::WideCharToMultiByte(CP_UTF8, 0, wstr.data(), (int)wstr.length(), NULL, NULL, NULL, NULL);
      if (nchars > 0)
      {
         str.resize(nchars);
         ::WideCharToMultiByte(CP_UTF8, 0, wstr.data(), (int)wstr.length(), const_cast<char*>(str.c_str()), nchars, NULL, NULL);
      }

      return str;
   }

   std::string GenerateGuid()
   {
      GUID guid;
      (void)CoCreateGuid(&guid);

      LPOLESTR guidString;
      (void)StringFromCLSID(guid, &guidString);

      std::wstring wstr(guidString);
      std::string str = ToStdString(wstr);

      CoTaskMemFree(guidString);
      return str;
   }
}

using namespace AmplitudeSDK;

AmplitudeEventFactory::AmplitudeEventFactory( std::shared_ptr<IUserIDRetriever> userIDRetriever,
                                              std::shared_ptr<IDeviceIDRetriever> deviceIDRetriever,
                                              std::shared_ptr<IUserPropertiesRetriever> userPropertiesRetriever )
   : _userIDRetriever( std::move( userIDRetriever ) )
   , _deviceIDRetriever( std::move( deviceIDRetriever ) )
   , _userPropertiesRetriever( std::move( userPropertiesRetriever ) )
{

}

AmplitudeEventFactory::~AmplitudeEventFactory()
{

}

AmplitudeEvent AmplitudeEventFactory::CreateEventWithProperties( const std::string& eventName,
                                                                 const std::map<std::string, std::string>& eventProperties ) const
{
   //TODO: Check eventName to make sure it isn't empty or to long
   if (eventName.empty())
   {
      throw new std::runtime_error("eventName is required and cannot be empty");
   }

   AmplitudeEvent result;

   result.InsertID = GenerateGuid();
   result.UserID = _userIDRetriever->GetUserID();
   result.DeviceID = _deviceIDRetriever->GetDeviceID();
   result.EventType = eventName;
   result.EventProperties = eventProperties;
   result.UserProperties = _userPropertiesRetriever->GetUserProperties();;
   result.Platform = "Put Platform HERE";
   result.OS = "Put OS HERE";
   result.OSVersion = "Put OSVersion HERE";
   result.Language = "Put Language HERE";
   result.Time = std::chrono::system_clock::now();

   return result;
}
