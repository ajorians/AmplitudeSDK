add_library(AmplitudeSDK STATIC
               Source/Amplitude.cpp
               Source/AmplitudeBackgroundEventTransmitter.cpp
               Source/AmplitudeEventFactory.cpp
               Source/AmplitudeEventQueue.cpp
               Source/AmplitudeExponentialBackoff.cpp
               Source/AmplitudeNetworkCalls.cpp
               Source/httplib.h
               Include/AmplitudeSDK/Amplitude.h
               Include/AmplitudeSDK/AmplitudeBackgroundEventTransmitter.h
               Include/AmplitudeSDK/AmplitudeEvent.h
               Include/AmplitudeSDK/AmplitudeEventFactory.h
               Include/AmplitudeSDK/AmplitudeEventQueue.h
               Include/AmplitudeSDK/AmplitudeExponentialBackoff.h
               Include/AmplitudeSDK/AmplitudeNetworkCalls.h
               Include/AmplitudeSDK/IAmplitude.h
               Include/AmplitudeSDK/IAmplitudeBackgroundEventTransmitter.h
               Include/AmplitudeSDK/IAmplitudeEventFactory.h
               Include/AmplitudeSDK/IAmplitudeEventQueue.h
               Include/AmplitudeSDK/IAmplitudeExponentialBackoff.h
               Include/AmplitudeSDK/IAmplitudeNetworkCalls.h
               Include/AmplitudeSDK/IDeviceIDRetriever.h
               Include/AmplitudeSDK/IUserIDRetriever.h
               Include/AmplitudeSDK/IUserPropertiesRetriever.h)

set_property(TARGET AmplitudeSDK PROPERTY CXX_STANDARD 20)

target_include_directories(AmplitudeSDK PRIVATE "C:/Users/a.orians/.CommonCppCache/repocache/openssl/6e9d7949b99e6f8be231e0b898ad5d686f39e4cb/artifacts/win/include"
                                                 Include)

target_link_libraries(AmplitudeSDK "C:/Users/a.orians/.CommonCppCache/repocache/openssl/6e9d7949b99e6f8be231e0b898ad5d686f39e4cb/artifacts/win/lib/libssl.lib")
target_link_libraries(AmplitudeSDK "C:/Users/a.orians/.CommonCppCache/repocache/openssl/6e9d7949b99e6f8be231e0b898ad5d686f39e4cb/artifacts/win/lib/libcrypto.lib")
