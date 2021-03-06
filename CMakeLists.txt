cmake_minimum_required(VERSION 3.5)

project(FLibraryCollection LANGUAGES CXX VERSION 1.2.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(FLogger)
add_subdirectory(FQLogger)
add_subdirectory(FString)
#add_subdirectory(FHammingCode)

#reds the text of example_1.cpp and writs it to the ExapleList.md
set(example1)
file(READ ${CMAKE_CURRENT_SOURCE_DIR}/examples/example_1/main.cpp example1)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/doc_files/ExampleList.md.in ${CMAKE_CURRENT_BINARY_DIR}/doc_files/ExampleList.md)

find_package(Doxygen)
if(NOT DOXYGEN_FOUND)
    message(WARNING "Doxygen not found, unable to generate documentation")
else()
    set(DOC_DEST_DIR ${CMAKE_BINARY_DIR} CACHE PATH "Path to the doxygen output")                      ## used in the doxyfile.in
    set(DOC_INPUT_ROOT_DIRS ${CMAKE_HOME_DIRECTORY} CACHE PATH "Path from where to start to parse")    ## used in the doxyfile.in
    set(DOC_EXCLUDE_PATTERNS_DIRS ${CMAKE_BINARY_DIR} CACHE STRING "Regex patterns exclusion")          ## used in the doxyfile.in
    set(DOC_COMMON_IMG_PATH ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "Path from which doxygen will be able to found referenced images")## used in the doxyfile.in
    configure_file(Doxyfile.in ${CMAKE_BINARY_DIR}/doxyfile @ONLY)
    add_custom_target(doc COMMAND ${DOXYGEN_EXECUTABLE} "${CMAKE_BINARY_DIR}/doxyfile"
        WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}
        COMMENT "Building user's documentation into doc build dir..."
        SOURCES
            Doxyfile.in
            README.md
            ./doc_files/Plans.md
            ./doc_files/LogoBig.md
            ./doc_files/ExampleList.md.in
    )
endif()

add_library(FLibraryCollection SHARED
  FLibraryCollection.cpp
  FLibraryCollection.hpp
)

configure_file(Version.in.hpp Version.hpp)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Logo/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Logo)


install(TARGETS FLibraryCollection DESTINATION lib)
install(FILES FLibraryCollection.hpp DESTINATION include/FLibraryCollection)
install(FILES ${CMAKE_BINARY_DIR}/Version.hpp DESTINATION include/FLibraryCollection)

target_compile_definitions(FLibraryCollection PRIVATE FLIBRARYCOLLECTION_LIBRARY)

