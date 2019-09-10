cmake_minimum_required(VERSION 3.3)
project(imgview)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_VERBOSE_MAKEFILE OFF)
SET(CMAKE_CXX_FLAGS "-Wall -Wno-unused-variable -Wno-unused-but-set-variable -Wno-unknown-pragmas")

find_package(Boost REQUIRED COMPONENTS
  thread
  system
  filesystem)

include_directories(
  include
)

list(APPEND LIBS
  ${Boost_LIBRARIES}
  glog
)

list(APPEND SRCS
  src/image.cpp
)

add_library(imgview SHARED ${SRCS})
target_link_libraries(imgview ${LIBS})
