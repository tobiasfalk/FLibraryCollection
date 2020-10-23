add_library(FString SHARED
  FString.cpp
  FString.hpp
)


target_compile_definitions(FString PRIVATE FLOGGER_LIBRARY)

install(TARGETS FString DESTINATION lib)
install(FILES FString.hpp DESTINATION include/FLibraryCollection/FString)
