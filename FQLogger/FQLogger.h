#ifndef FQLOGGER_H
#define FQLOGGER_H

#include <iostream>
#include <QtCore>
#include <QString>

#include "../FLogger/FLogger.h"

#include "FQLogger_global.h"

///
/// The FQLogger namespace is where all the QFLogger things are
///
namespace FQLogger
{

///
/// \brief The Logger class
///
/// Dat Time Formate: YYYY-MM-DD|HH:mm:ss<br>
/// <br>
/// it Currently(FLibraryCollection 1.1) just converts the QString to an std::string an givs it the FLogger Libary to proces<br>
/// but it is still posible tu use the FLogger functions because the class was publicly inherited
///
class FQLOGGER_EXPORT Logger : public FLogger::Logger
{
public:
    ///
    /// \brief Logger the constructor of the class
    /// \param logName the name of the log
    /// \param path the path wher the log is placed the standerd is ./
    ///
    Logger(QString logName, QString path = "./");

    ///
    /// \brief the FLogger destructor
    ///
    /// it first writs the text that was setwith with setEndText and than closes the log file
    ///
    ~Logger();


    ///
    /// \brief write writes the text with date and time in white
    /// \param text the text that will be written
    ///
    void write(QString text);
    ///
    /// \brief error writes the text with date and time in red
    /// \param text the text that will be written
    ///
    void error(QString text);
    ///
    /// \brief fatalError writes the text with date and time in white with red backround
    /// \param text the text that will be written
    ///
    void fatalError(QString text);
    ///
    /// \brief warning writes the text with date and time in yellow
    /// \param text the text that will be written
    ///
    void warning(QString text);
    ///
    /// \brief info writes the text with date and time in Cyan
    /// \param text the text that will be written
    ///
    void info(QString text);

    ///
    /// \brief write writes the text with date and time in white
    /// \param text the text that will be written
    /// \param line The line of the Message__LINE__
    /// \param codeFile The file from wher the messag is writen from __FILE__
    /// \param func The Function  from wher the messag is writen from __func__
    ///
    void write(QString text, int line, QString codeFile, QString func);
    ///
    /// \brief error writes the text with date and time in red
    /// \param text the text that will be written
    /// \param line The line of the Message__LINE__
    /// \param codeFile The file from wher the messag is writen from __FILE__
    /// \param func The Function  from wher the messag is writen from __func__
    ///
    void error(QString text, int line, QString codeFile, QString func);
    ///
    /// \brief fatalError writes the text with date and time in white with red backround
    /// \param text the text that will be written
    /// \param line The line of the Message__LINE__
    /// \param codeFile The file from wher the messag is writen from __FILE__
    /// \param func The Function  from wher the messag is writen from __func__
    ///
    void fatalError(QString text, int line, QString codeFile, QString func);
    ///
    /// \brief warning writes the text with date and time in yellow
    /// \param text the text that will be written
    /// \param line The line of the Message__LINE__
    /// \param codeFile The file from wher the messag is writen from __FILE__
    /// \param func The Function  from wher the messag is writen from __func__
    ///
    void warning(QString text, int line, QString codeFile, QString func);
    ///
    /// \brief info writes the text with date and time in Cyan
    /// \param text the text that will be written
    /// \param line The line of the Message__LINE__
    /// \param codeFile The file from wher the messag is writen from __FILE__
    /// \param func The Function  from wher the messag is writen from __func__
    ///
    void info(QString text, int line, QString codeFile, QString func);

    ///
    /// \brief setStartText writes the text without date and time in white
    /// \param text the text that will be written
    ///
    bool setStartText(QString text);
    ///
    /// \brief setEndText writes the text with date and time in Cyan when the objekt is deleted and the file will be closed
    /// \param text the text that will be written the standart is "END"
    ///
    void setEndText(QString text);

};

}

#endif // FQLOGGER_H
