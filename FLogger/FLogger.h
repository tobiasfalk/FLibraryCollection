#ifndef FLOGGER_H
#define FLOGGER_H

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <sys/time.h>
#include <vector>

#include <chrono>
#include <ctime>

///
/// The FLogger namespace is where all the FLogger things are
///
namespace FLogger
{

///
/// \brief The Logger class
///
/// Dat Time Formate: YYYY-MM-DD|HH:mm:ss<br>
/// for Multitails the configuration:<br>
/// #defaultcscheme:flogger<br>
/// colorscheme:flogger<br>
/// cs_re:yellow:WARNING .*$<br>
/// cs_re:green:INFO .*$<br>
/// cs_re:red:ERROR .*$<br>
/// cs_re:white,red:FATAL .*$<br>
///
class Logger
{

public:
    ///
    /// \brief Logger the constructor of the class
    /// \param logName the name of the log
    /// \param path the path wher the log is placed the standerd is ./
    ///
    Logger(std::string logName, std::string path = "./");
    ///
    /// \brief the FLogger destructor
    ///
    /// it first writs the text that was setwith with setEndText and than closes the log file
    ///
    ~Logger();


    ///
    /// \brief write writes the text with date and time
    /// \param text the text that will be written
    ///
    void write(std::string text);
    ///
    /// \brief error writes the text with date and time with ERROR after the time
    /// \param text the text that will be written
    ///
    void error(std::string text);
    ///
    /// \brief fatalError writes the text with date and time with FATAL ERROR after the time
    /// \param text the text that will be written
    ///
    void fatalError(std::string text);
    ///
    /// \brief warning writes the text with date and time with WARNING after the time
    /// \param text the text that will be written
    ///
    void warning(std::string text);
    ///
    /// \brief info writes the text with date and time with INFO after the time
    /// \param text the text that will be written
    ///
    void info(std::string text);

    ///
    /// \brief write writes the text with date and time
    /// \param text the text that will be written
    /// \param line The line of the Message__LINE__
    /// \param codeFile The file from wher the messag is writen from __FILE__
    /// \param func The Function  from wher the messag is writen from __func__
    ///
    void write(std::string text, int line, std::string codeFile, std::string func);
    ///
    /// \brief error writes the text with date and time with ERROR after the time
    /// \param text the text that will be written
    /// \param line The line of the Message__LINE__
    /// \param codeFile The file from wher the messag is writen from __FILE__
    /// \param func The Function  from wher the messag is writen from __func__
    ///
    void error(std::string text, int line, std::string codeFile, std::string func);
    ///
    /// \brief fatalError writes the text with date and time with FATAL ERROR after the time
    /// \param text the text that will be written
    /// \param line The line of the Message__LINE__
    /// \param codeFile The file from wher the messag is writen from __FILE__
    /// \param func The Function  from wher the messag is writen from __func__
    ///
    void fatalError(std::string text, int line, std::string codeFile, std::string func);
    ///
    /// \brief warning writes the text with date and time with WARNING after the time
    /// \param text the text that will be written
    /// \param line The line of the Message__LINE__
    /// \param codeFile The file from wher the messag is writen from __FILE__
    /// \param func The Function  from wher the messag is writen from __func__
    ///
    void warning(std::string text, int line, std::string codeFile, std::string func);
    ///
    /// \brief info writes the text with date and time with INFO after the time
    /// \param text the text that will be written
    /// \param line The line of the Message__LINE__
    /// \param codeFile The file from wher the messag is writen from __FILE__
    /// \param func The Function  from wher the messag is writen from __func__
    ///
    void info(std::string text, int line, std::string codeFile, std::string func);

    ///
    /// \brief setStartText writes the text without date and time
    /// \param text the text that will be written
    ///
    bool setStartText(std::string text);
    ///
    /// \brief setEndText writes the text with date and time in Cyan when the objekt is deleted and the file will be closed
    /// \param text the text that will be written the standart is "END"
    ///
    void setEndText(std::string text);

    //friend std::ostream& operator<<(std::ostream& os, QString &text);

private:
    ///
    /// \brief file the name of the file wher the log is written in
    ///
    std::fstream file;
    ///
    /// \brief endText the text that will be written at the end
    ///
    std::string endText = "END";

    ///
    /// \brief writeToFile writes the text without date and time in white
    /// \param text the text that will be written
    ///
    void writeToFile(std::string text);
    ///
    /// \brief currentDateTime returns the current date and time
    /// \return the format is YYYY-MM-DD|HH:mm:ss
    ///
    const std::string currentDateTime();

    ///
    /// \brief StartText
    /// StartText is for control that the start text will only be writen ones or other Messages wher alredy writen
    ///
    bool StartText = 1;
};

}

#endif // FLOGGER_H
