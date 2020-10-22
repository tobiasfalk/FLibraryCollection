#include "FQLogger.hpp"
#include <cstdarg>

using namespace FQLogger;
Logger::Logger(QObject *parent) : QObject(parent)
{
}

Logger::Logger(std::string Log_Name, std::string Path, QObject *parent) : QObject(parent)
{
    logName = Log_Name;
    path = Path;
}

void Logger::write(std::string text, ...)
{
    va_list arg;
    va_start(arg, text);
    text = stringFormate(text, arg);
    va_end(arg);
    text = currentDateTime() + " \t\t" + text;
    file << text  << std::endl;
    std::cout << text << std::endl;
}

void Logger::error(std::string text, ...)
{
    va_list arg;
    va_start(arg, text);
    text = stringFormate(text, arg);
    va_end(arg);
    text = currentDateTime() + " ERROR \t"  + text;
    file << text  << std::endl;
    std::cout << text << std::endl;
}

void Logger::fatalError(std::string text, ...)
{
    va_list arg;
    va_start(arg, text);
    text = stringFormate(text, arg);
    va_end(arg);
    text = currentDateTime() + " FATAL \t" + text;
    file << text  << std::endl;
    std::cout << text << std::endl;
}

void Logger::warning(std::string text, ...)
{
    va_list arg;
    va_start(arg, text);
    text = stringFormate(text, arg);
    va_end(arg);
    text = currentDateTime() + " WARNING \t" + text;
    file << text  << std::endl;
    std::cout << text << std::endl;
}

void Logger::info(std::string text, ...)
{
    va_list arg;
    va_start(arg, text);
    text = stringFormate(text, arg);
    va_end(arg);
    text = currentDateTime() + " INFO \t" + text;
    file << text  << std::endl;
    std::cout << text << std::endl;
}

void Logger::write(int line, std::string codeFile, std::string func, std::string text, ...)
{
    va_list arg;
    va_start(arg, text);
    text = stringFormate(text, arg);
    va_end(arg);
    text = currentDateTime() + " \t\tFile: " + codeFile + " Line: " + std::to_string(line) + " Function: " + func + " " + text;
    file << text  << std::endl;
    std::cout << text << std::endl;
}

void Logger::error(int line, std::string codeFile, std::string func, std::string text, ...)
{
    va_list arg;
    va_start(arg, text);
    text = stringFormate(text, arg);
    va_end(arg);
    text = currentDateTime() + " ERROR \tFile: " + codeFile + " Line: " + std::to_string(line) + " Function: " + func + " " + text ;
    file << text  << std::endl;
    std::cout << text << std::endl;
}

void Logger::fatalError(int line, std::string codeFile, std::string func, std::string text, ...)
{
    va_list arg;
    va_start(arg, text);
    text = stringFormate(text, arg);
    va_end(arg);
    text = currentDateTime()  + " FATAL \tFile: " + codeFile + " Line: " + std::to_string(line) + " Function: " + func + " " + text;
    file << text  << std::endl;
    std::cout << text << std::endl;
}

void Logger::warning(int line, std::string codeFile, std::string func, std::string text, ...)
{
    va_list arg;
    va_start(arg, text);
    text = stringFormate(text, arg);
    va_end(arg);
    text = currentDateTime() + " WARNING \tFile: " + codeFile + " Line: " + std::to_string(line) + " Function: " + func + " " + text;
    file << text  << std::endl;
    std::cout << text << std::endl;
    Started = 0;
}

void Logger::info(int line, std::string codeFile, std::string func, std::string text, ...)
{
    va_list arg;
    va_start(arg, text);
    text = stringFormate(text, arg);
    va_end(arg);
    text = currentDateTime() + " INFO \tFile: " + codeFile + " Line: " + std::to_string(line) + " Function: " + func  + " " + text;
    file << text  << std::endl;
    std::cout << text << std::endl;
}

void Logger::setEndText(std::string text)
{
    endText = text;
}

void Logger::writeToFile(std::string text)
{
    file << text  << std::endl;
}

bool Logger::getStarted() const
{
    return Started;
}

bool Logger::getTerminalOut() const
{
    return TerminalOut;
}

void Logger::setTerminalOut(const bool &value)
{
    TerminalOut = value;
}

void Logger::setStartText(const std::string &value)
{
    if(!Started)
    {
        StartText = value;
    }
}

std::string Logger::getStartText() const
{
    return StartText;
}

std::string Logger::getPath() const
{
    return path;
}

void Logger::setPath(const std::string &value)
{
    if(!Started)
    {
        path = value;
    }
}

std::string Logger::getLogName() const
{
    return logName;
}

void Logger::setLogName(const std::string &value)
{
    if(!Started)
    {
        logName = value;
    }
}

Logger::~Logger()
{
    writeToFile(endText);
    file.close();
}

bool Logger::start()
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
            return 0;
        }
        file << StartText  << std::endl;
        return 1;
    }
    return 0;
}

std::string Logger::stringFormate(std::string format, va_list args )
{
    char *cstr = new char[format.length() + 1];
    strcpy(cstr, format.c_str());
    char buffer[65536];
    vsprintf (buffer, cstr, args);
    delete [] cstr;
    return buffer;
}

Qt::DateFormat Logger::getDateFormate() const
{
    return dateFormate;
}

void Logger::setDateFormate(const Qt::DateFormat &value)
{
    if(Started)
    {
        dateFormate = value;
    }
}

const std::string Logger::currentDateTime() {
    QDateTime time = QDateTime::currentDateTime();
    return time.toString(dateFormate).toStdString();
}