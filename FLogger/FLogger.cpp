#include "FLogger.hpp"

using namespace FLogger;
Logger::Logger(std::string logName, std::string path)
{
    std::string time = currentDateTime();
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
    text = currentDateTime() + " \t\t" + text;
    file << text  << std::endl;
    std::cout << text << std::endl;
    StartText = 0;
}

void Logger::error(std::string text)
{
    text = currentDateTime() + " ERROR \t"  + text;
    file << text  << std::endl;
    std::cout << text << std::endl;
    StartText = 0;
}

void Logger::fatalError(std::string text)
{
    text = currentDateTime() + " FATAL \t" + text;
    file << text  << std::endl;
    std::cout << text << std::endl;
    StartText = 0;
}

void Logger::warning(std::string text)
{
    text = currentDateTime() + " WARNING \t" + text;
    file << text  << std::endl;
    std::cout << text << std::endl;
    StartText = 0;
}

void Logger::info(std::string text)
{
    text = currentDateTime() + " INFO \t" + text;
    file << text  << std::endl;
    std::cout << text << std::endl;
    StartText = 0;
}

void Logger::write(std::string text, int line, std::string codeFile, std::string func)
{
    text = currentDateTime() + " \t\tFile: " + codeFile + " Line: " + std::to_string(line) + " Function: " + func + " " + text;
    file << text  << std::endl;
    std::cout << text << std::endl;
    StartText = 0;
}

void Logger::error(std::string text, int line, std::string codeFile, std::string func)
{
    text = currentDateTime() + " ERROR \tFile: " + codeFile + " Line: " + std::to_string(line) + " Function: " + func + " " + text ;
    file << text  << std::endl;
    std::cout << text << std::endl;
    StartText = 0;
}

void Logger::fatalError(std::string text, int line, std::string codeFile, std::string func)
{
    text = currentDateTime()  + " FATAL \tFile: " + codeFile + " Line: " + std::to_string(line) + " Function: " + func + " " + text;
    file << text  << std::endl;
    std::cout << text << std::endl;
    StartText = 0;
}

void Logger::warning(std::string text, int line, std::string codeFile, std::string func)
{
    text = currentDateTime() + " WARNING \tFile: " + codeFile + " Line: " + std::to_string(line) + " Function: " + func + " " + text;
    file << text  << std::endl;
    std::cout << text << std::endl;
    StartText = 0;
}

void Logger::info(std::string text, int line, std::string codeFile, std::string func)
{
    text = currentDateTime() + " INFO \tFile: " + codeFile + " Line: " + std::to_string(line) + " Function: " + func  + " " + text;
    file << text  << std::endl;
    std::cout << text << std::endl;
    StartText = 0;
}

bool Logger::setStartText(std::string text)
{
    if(StartText)
    {
        writeToFile(text);
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
        text = currentDateTime + text + "\n";
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
    writeToFile(endText);
    file.close();
}
