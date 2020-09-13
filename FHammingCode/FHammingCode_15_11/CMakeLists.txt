cmake_minimum_required(VERSION 3.5)

project(FLibraryCollection LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(FHammingCode_15_11 SHARED
  FHammingCode_15_11.cpp
  FHammingCode_15_11.h
)

install(TARGETS FHammingCode_15_11 DESTINATION lib)
install(FILES FHammingCode_15_11.h DESTINATION include/FLibraryCollection/FHammingCode)


target_compile_definitions(FHammingCode_15_11 PRIVATE FHAMMINGCODE_15_11_LIBRARY)
