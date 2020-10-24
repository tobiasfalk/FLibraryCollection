#ifndef FSTRING_HPP
#define FSTRING_HPP

#include <iostream>
#include <string>

#include <vector>
#include <list>

///
/// The FString namespace is where all the FString things are
/// it inherits all from the std::string
///
namespace FString
{

///
/// \brief The string class
///
class string : std::string
{
public:
    using std::string::basic_string;

    ///
    /// \brief string the constructor of the class
    ///
    explicit string();

    ///
    /// \brief the string destructor
    ///
    ///
    ~string();

    ///
    /// \brief operator =
    /// \param str as const char* str
    /// \return
    ///
    string& operator=(const char* str);

    ///
    /// \brief operator =
    /// \param str as std::string str
    /// \return
    ///
    string& operator=(std::string str);

    ///
    /// \brief split splits the given string in to an vector of strings
    /// \param str th given string
    /// \param splitter the character where it will be splited(it will be removed
    /// \return std::vector<string>
    ///
    std::vector<string> split(string str, const char splitter);
    ///
    /// \brief split splits string in to an vector of strings
    /// \param splitter the character where it will be splited(it will be removed
    /// \return std::vector<string>
    ///
    std::vector<string> split(const char splitter);

    ///
    /// \brief exists returns true when the given charector exists in the given string
    /// \param str the given string
    /// \param character the given character
    /// \return boolean
    ///
    bool exists(string str, const char character);
    ///
    /// \brief exists returns true when the given charector exists in the string
    /// \param character the given character
    /// \return boolean
    ///
    bool exists(const char character);

    ///
    /// \brief numberof returns how often the given character exists in the given string
    /// \param str
    /// \param character
    /// \return unsigned int
    ///
    unsigned int numberof(string str, const char character);
    ///
    /// \brief numberof returns how often the given character exists in the string
    /// \param character
    /// \return unsigned int
    ///
    unsigned int numberof(const char character);

private:
};

}

#endif // FSTRING_HPP
