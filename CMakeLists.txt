cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(Server)

#COMPILE WITH C++ 11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

option(UnitTest "UnitTest" OFF)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core)
find_package(Qt5Network)
find_package(Qt5Test)

file(GLOB API_SRC
  "API/*.h"
  "API/*.cpp"
  "API/DebianMining/*.h"
  "API/DebianMining/*.cpp"
  "API/Windows7Mining/*.cpp"
  "API/Windows7Mining/*.h"
  "API/Windows10Mining/*.cpp"
  "API/Windows10Mining/*.h"
  "controller/*.h"
  "controller/*.cpp"
  )

file(GLOB SRV_SRC
  "*.h"
  "requestmapper.cpp"
  )

if (UnitTest)
  set (SRV_SRC ${SRV_SRC} Test/unitTestAPI.h Test/unitTestAPI.cpp)
else()
  set (SRV_SRC ${SRV_SRC} main.cpp)
endif (UnitTest)

#ADD EXTERNAL LIBS
include_directories ("${PROJECT_SOURCE_DIR}/Lib/QtWebApp/httpserver/")
add_subdirectory (Lib/QtWebApp/httpserver)
set (EXTRA_LIBS ${EXTRA_LIBS} httpserver)

add_executable(server ${SRV_SRC} ${API_SRC})
target_link_libraries(server Qt5::Core Qt5::Network Qt5::Test ${EXTRA_LIBS})