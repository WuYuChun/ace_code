cmake_minimum_required(VERSION 2.8)

add_executable(server_ace server.cpp )
target_link_libraries(server_ace ACE)


add_executable(client_ace client.cpp )
target_link_libraries(client_ace ACE)

