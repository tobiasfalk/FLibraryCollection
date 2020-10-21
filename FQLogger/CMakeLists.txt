find_package(Qt5 COMPONENTS Core REQUIRED)

add_library(FQLogger SHARED
  FQLogger_global.hpp
  FQLogger.cpp
  FQLogger.hpp
)

target_link_libraries(FQLogger PRIVATE Qt5::Core)

target_compile_definitions(FQLogger PRIVATE FQLOGGER_LIBRARY)

install(TARGETS FQLogger DESTINATION lib)
install(FILES FQLogger.hpp DESTINATION include/FLibraryCollection/FQLogger)
install(FILES FQLogger_global.hpp DESTINATION include/FLibraryCollection/FQLogger)

