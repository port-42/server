cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

#COMPILE WITH C++ 11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Qt5Network)

file(GLOB HTTPSERVER_SRC
  "*.h"
  "*.cpp"
  )

add_library(httpserver ${HTTPSERVER_SRC})
target_link_libraries(httpserver Qt5::Network)