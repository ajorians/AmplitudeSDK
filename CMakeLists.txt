cmake_minimum_required(VERSION 3.10)

#if(NOT CMAKE_GENERATOR MATCHES "Visual Studio.*")
#    message(FATAL_ERROR "Visual Studio generator is required for this project.")
#endif()

# set the project name
project(AmplitudeSDK LANGUAGES CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(AmplitudeSDK)
#add_subdirectory(AmplitudeInterop)
#add_subdirectory(AmplitudeWPFHarness)