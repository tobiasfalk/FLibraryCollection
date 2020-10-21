add_library(FLogger SHARED
  FLogger.cpp
  FLogger.hpp
)


target_compile_definitions(FLogger PRIVATE FLOGGER_LIBRARY)

install(TARGETS FLogger DESTINATION lib)
install(FILES FLogger.hpp DESTINATION include/FLibraryCollection/FLogger)
