cmake_minimum_required(VERSION 3.12)
project(ace)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/local/include)
link_libraries(/usr/local/lib/libACE.so)

add_subdirectory(ace_unit_0)

add_executable(ace main.cpp )
target_link_libraries(ace ACE)