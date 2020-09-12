#include "FLogger.h"

using namespace FLogger;
Logger::Logger(std::string logName, std::string path)
{
    std::string time = this->currentDateTime();
    std::string fileName = path + time + "-" + logName;
    if (fileName.size() > 0)
    {
        file.open(fileName, std::ios::app);
        if (!file.good())
        {
            std::cout << "Not Open" << std::endl;
            std::cout << fileName << std::endl;
        }

    }
}

void Logger::write(std::string text)
{
    text = this->currentDateTime() + " " + text;
    file << text  << std::endl;
    std::cout << text << std::endl;
    StartText = 0;
}

void Logger::error(std::string text)
{
    text = "\033[0;31m" + this->currentDateTime() + " "  + text + "\033[0m";
    file << text  << std::endl;
    std::cout << text << std::endl;
    StartText = 0;
}

void Logger::fatalError(std::string text)
{
    text = "\033[1;37;41m" + this->currentDateTime() + " " + text + "\033[0m";
    file << text  << std::endl;
    std::cout << text << std::endl;
    StartText = 0;
}

void Logger::warning(std::string text)
{
    text = "\033[1;33m" + this->currentDateTime() + " " + text + "\033[0m";
    file << text  << std::endl;
    std::cout << text << std::endl;
    StartText = 0;
}

void Logger::info(std::string text)
{
    text = "\033[1;36m" + this->currentDateTime() + " " + text + "\033[0m";
    file << text  << std::endl;
    std::cout << text << std::endl;
    StartText = 0;
}

void Logger::write(std::string text, int line, std::string codeFile, std::string func)
{
    text = this->currentDateTime() + " File: " + codeFile + " Line: " + std::to_string(line) + " Function: " + func + " Write: " + text;
    file << text  << std::endl;
    std::cout << text << std::endl;
    StartText = 0;
}

void Logger::error(std::string text, int line, std::string codeFile, std::string func)
{
    text = "\033[0;31m" + this->currentDateTime() + " File: " + codeFile + " Line: " + std::to_string(line) + " Function: " + func + " Error: "  + text + "\033[0m";
    file << text  << std::endl;
    std::cout << text << std::endl;
    StartText = 0;
}

void Logger::fatalError(std::string text, int line, std::string codeFile, std::string func)
{
    text = "\033[1;37;41m" + this->currentDateTime()  + " File: " + codeFile + " Line: " + std::to_string(line) + " Function: " + func + " Fatal Error: " + text + "\033[0m";
    file << text  << std::endl;
    std::cout << text << std::endl;
    StartText = 0;
}

void Logger::warning(std::string text, int line, std::string codeFile, std::string func)
{
    text = "\033[1;33m" + this->currentDateTime() + " File: " + codeFile + " Line: " + std::to_string(line) + " Function: " + func + " Warnin: " + text + "\033[0m";
    file << text  << std::endl;
    std::cout << text << std::endl;
    StartText = 0;
}

void Logger::info(std::string text, int line, std::string codeFile, std::string func)
{
    text = "\033[1;36m" + this->currentDateTime() + " File: " + codeFile + " Line: " + std::to_string(line) + " Function: " + func + " Info: " + text + "\033[0m";
    file << text  << std::endl;
    std::cout << text << std::endl;
    StartText = 0;
}

bool Logger::setStartText(std::string text)
{
    if(StartText)
    {
        this->writeToFile(text);
        StartText = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}

void Logger::setEndText(std::string text)
{
    endText = text;
}

void Logger::writeToFile(std::string text)
{
    file << text  << std::endl;
}

/*std::ostream& Logger::operator<<(std::ostream& os, std::string &text)
{
    if (m_showDate)
    {
        text = this->currentDateTime + text + "\n";
    }
    QTextStream out(file);
    out.setCodec("UTF-8");
    if (file != 0)
    {
        out << text;
    }
    os << text.toStdString();
    return os;
}*/

const std::string Logger::currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d|%X", &tstruct);

    return buf;
}


Logger::~Logger()
{
    this->writeToFile(endText);
    file.close();
}
