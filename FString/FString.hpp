#ifndef FSTRING_HPP
#define FSTRING_HPP

#include <iostream>
#include <string>

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
    /// \brief Logger the constructor of the class
    ///
    explicit string();

    ///
    /// \brief the FLogger destructor
    ///
    /// it first writs the text that was setwith with setEndText and than closes the log file
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

private:
};

}

#endif // FSTRING_HPP
