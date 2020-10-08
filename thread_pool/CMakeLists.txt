cmake_minimum_required(VERSION 2.8.9)
project (demo)
add_executable(demo demo.cpp thread_pool.cpp)
target_link_libraries(demo pthread)
