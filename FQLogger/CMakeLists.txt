cmake_minimum_required(VERSION 3.5)

project(FLibraryCollection LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core REQUIRED)

add_library(FQLogger SHARED
  FQLogger_global.hpp
  FQLogger.cpp
  FQLogger.hpp
)

target_link_libraries(FQLogger PRIVATE Qt5::Core)

target_compile_definitions(FQLogger PRIVATE FQLOGGER_LIBRARY)

install(TARGETS FQLogger DESTINATION lib)
install(FILES FQLogger.h DESTINATION include/FLibraryCollection/FQLogger)
install(FILES FQLogger_global.h DESTINATION include/FLibraryCollection/FQLogger)

