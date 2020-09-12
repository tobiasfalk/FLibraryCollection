cmake_minimum_required(VERSION 3.5)

project(FLibraryCollection LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(FLogger SHARED
  FLogger.cpp
  FLogger.h
)

target_compile_definitions(FLogger PRIVATE FLOGGER_LIBRARY)

install(TARGETS FLogger DESTINATION lib)
install(FILES FLogger.h DESTINATION include/FLibraryCollection/FLogger)
