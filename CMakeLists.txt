cmake_minimum_required(VERSION 3.10)

if (EXISTS ${CMAKE_BINARY_DIR}/conan_paths.cmake)
  include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
endif()

find_package(is-msgs REQUIRED)
find_package(boost REQUIRED)

add_executable(app.bin app.cpp stream_pb.cpp stream_pb.hpp)

target_link_libraries(
  app.bin
 PRIVATE
  is-msgs::is-msgs
  boost::boost
)

set_property(TARGET app.bin PROPERTY CXX_STANDARD 14)