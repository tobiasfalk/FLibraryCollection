#include "FString.hpp"

FString::string::string()
{

}

FString::string::~string()
{

}

FString::string &FString::string::operator=(std::string str)
{
    this->assign(str);
    return *this;
}

std::vector<FString::string> FString::string::split(string str, const char splitter)
{
    std::vector<string> strc;
    for(unsigned int i = 0; i < str.numberof(splitter); i++)
    {
        string strt = str;
        strt.erase((strt.find_first_of(splitter) - 1), (strt.length() - strt.find_first_of(splitter)));
        strc.push_back(strt);
        str.erase(0, str.find_first_of(splitter));
    }
    strc.push_back(str);
    return strc;
}

std::vector<FString::string> FString::string::split(const char splitter)
{
    std::vector<string> strc;
    string strt1 = *this;
    for(unsigned int i = 0; i < numberof(splitter); i++)
    {
        string strt2 = strt1;
        strt2.erase((strt2.find_first_of(splitter)), (strt2.length() - strt2.find_first_of(splitter)));
        strc.push_back(strt2);
        strt1.erase(0, strt1.find_first_of(splitter) + 1);
    }
    strc.push_back(strt1);
    return strc;
}

bool FString::string::exists(string str, const char character)
{
    std::string::size_type n = 0;
    n = str.find(character);
    if (n == std::string::npos) {
        return false;
    } else {
        return true;
    }
}

bool FString::string::exists(const char character)
{
    std::string::size_type n = 0;
    n = find(character);
    if (n == std::string::npos) {
        return false;
    } else {
        return true;
    }
}

unsigned int FString::string::numberof(string str, const char character)
{
    unsigned int number = 0;
    while (exists(str, character))
    {
        str.erase(str.find_first_of(character), 1);
        number++;
    }
    return number;
}

unsigned int FString::string::numberof(const char character)
{
    string str = *this;
    unsigned int number = 0;
    while (exists(str, character))
    {
        str.erase(str.find_first_of(character), 1);
        number++;
    }
    return number;
}
