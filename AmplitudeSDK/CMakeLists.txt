add_library(AmplitudeSDK STATIC
               Amplitude.cpp
               Amplitude.h
               IAmplitude.h)

set_property(TARGET AmplitudeSDK PROPERTY CXX_STANDARD 20)