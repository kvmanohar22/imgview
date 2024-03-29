cmake_minimum_required(VERSION 3.3)
project(imgview)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_VERBOSE_MAKEFILE OFF)
SET(CMAKE_CXX_FLAGS "-Wall -Wno-unused-variable -Wno-unused-but-set-variable -Wno-unknown-pragmas -Wpedantic")

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(
  include
  include/imgview/ext
)

list(APPEND LIBS
  glfw
)

list(APPEND SRCS
  src/image.cpp
  src/mosaic.cpp
  src/window.cpp
  src/shader.cpp
  src/renderer.cpp
)

add_library(imgview SHARED
  ${SRCS}
  include/imgview/ext/stb_image.h
  src/glw3.c
)
target_link_libraries(imgview ${LIBS})

add_executable(test_simple1 test/test_simple1.cpp)
target_link_libraries(test_simple1 imgview)

add_executable(test_simple2 test/test_simple2.cpp)
target_link_libraries(test_simple2 imgview)
