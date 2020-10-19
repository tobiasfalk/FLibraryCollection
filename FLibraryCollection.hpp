#ifndef FLIBRARYCOLLECTION_HPP
#define FLIBRARYCOLLECTION_HPP
//https://de.wikipedia.org/wiki/Versionsnummer

#include <iostream>
#include <vector>
#include "Version.hpp"

namespace FLibraryCollection
{
///
/// \brief get_version Returns the Library Version
/// \return The version as String
///
/// [major].[minor].[patch]<br>
/// https://de.wikipedia.org/wiki/Versionsnummer<br>
/// 42
///
std::string get_version();

///
/// \brief get_version_int Returns the Library Version
/// \return The version as integar Vector Typicaly with 3 elements
///
/// [element1].[element2].[element3]<br>
/// [major].[minor].[patch]<br>
/// https://de.wikipedia.org/wiki/Versionsnummer
///
std::vector<int> get_version_int();
}

#endif // FLIBRARYCOLLECTION_HPP
