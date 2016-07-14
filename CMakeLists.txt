cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(Server)

# Instruct CMake to look for brewed qt5 files on OSX
if (${APPLE})
  set(CMAKE_PREFIX_PATH /usr/local/opt/qt5)
endif(${APPLE})

#COMPILE WITH C++ 11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set (Server_VERSION_MAJOR 1)
set (Server_VERSION_MINOR 0)

option(UnitTest "UnitTest" OFF)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Test REQUIRED)

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

# GENERATION OF THE INSTALLERS FOR DEBIAN
INSTALL(TARGETS server DESTINATION port)
install (FILES Port-Server.ini DESTINATION port)

SET(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Alex ARNAUD") #required

# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE
  "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set (CPACK_PACKAGE_VERSION_MAJOR "${Server_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${Server_VERSION_MINOR}")
include (CPack)