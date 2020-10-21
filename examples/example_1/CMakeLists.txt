cmake_minimum_required(VERSION 3.5)

project(example_1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(example_1
  main.cpp
)

target_link_libraries(example_1 PRIVATE FLogger)
