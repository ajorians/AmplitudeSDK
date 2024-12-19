add_executable(AmplitudeSDKHarness main.cpp)

set_property(TARGET AmplitudeSDKHarness PROPERTY CXX_STANDARD 20)

target_include_directories(AmplitudeSDKHarness PRIVATE ../AmplitudeSDK/Include)

target_link_libraries(AmplitudeSDKHarness AmplitudeSDK)
