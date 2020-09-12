#include "FLibraryCollection.h"

std::string FLibraryCollection::get_version()
{
    std::string Version;
    Version.append(std::to_string(FLCVersion_MAJOR) + "." + std::to_string(FLCVersion_MINOR) + "." + std::to_string(FLCVersion_PATCH));
    return Version;
}

std::vector<int> FLibraryCollection::get_version_int()
{
    std::vector<int> Version;
    Version.push_back(FLCVersion_MAJOR);
    Version.push_back(FLCVersion_MINOR);
    Version.push_back(FLCVersion_PATCH);
    return Version;
}
