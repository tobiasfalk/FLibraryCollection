#ifndef FQLOGGER_HPP
#define FQLOGGER_HPP

#include "FQLogger_global.hpp"

#include <iostream>
#include <string>
#include <fstream>

#include <QDateTime>
#include <QObject>

///
/// The FQLogger namespace is where all the FQLogger things are
/// the differenz to FLogger curently is that you can set the date time formate and that it is an QObject
///
namespace FQLogger
{
///
/// \brief The FLogger_e enum
///
enum class FLogger_e
{
    end
};

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
class Logger : public QObject
{
    Q_OBJECT
public:
    ///
    /// \brief Logger the constructor of the class
    ///
    explicit Logger(QObject *parent = nullptr);

    ///
    /// \brief Logger the constructor of the class
    /// \param logName the name of the log
    /// \param path the path wher the log is placed the standerd is ./
    /// \param parent the Qt standart parent
    ///
    explicit Logger(std::string logName, std::string path = "./", QObject *parent = nullptr);

    ///
    /// \brief the FQLogger destructor
    ///
    /// it first writs the text that was setwith with setEndText and than closes the log file
    ///
    ~Logger();

    ///
    /// \brief start creats and opens the fiel and writes the start text<br>
    /// after it was started the functions setDateFormate, setLogName, setPath
    /// \return returns 1 when it was sucsesfull
    ///
    bool start();

    ///
    /// \brief write writes the text with date and time<br>The maximal length of the finished sting is 65536 charectars
    /// \param text the text that will be written
    ///
    void write(std::string text, ...);
    ///
    /// \brief error writes the text with date and time with ERROR after the time<br>The maximal length of the finished sting is 65536 charectars
    /// \param text the text that will be written
    ///
    void error(std::string text, ...);
    ///
    /// \brief fatalError writes the text with date and time with FATAL ERROR after the time<br>The maximal length of the finished sting is 65536 charectars
    /// \param text the text that will be written
    ///
    void fatalError(std::string text, ...);
    ///
    /// \brief warning writes the text with date and time with WARNING after the time<br>The maximal length of the finished sting is 65536 charectars
    /// \param text the text that will be written
    ///
    void warning(std::string text, ...);
    ///
    /// \brief info writes the text with date and time with INFO after the time<br>The maximal length of the finished sting is 65536 charectars
    /// \param text the text that will be written
    ///
    void info(std::string text, ...);

    ///
    /// \brief write writes the text with date and time<br>The maximal length of the finished sting is 65536 charectars
    /// \param line The line of the Message__LINE__
    /// \param codeFile The file from wher the messag is writen from __FILE__
    /// \param func The Function  from wher the messag is writen from __func__
    /// \param text the text that will be written
    ///
    void write(int line, std::string codeFile, std::string func, std::string text, ...);
    ///
    /// \brief error writes the text with date and time with ERROR after the time<br>The maximal length of the finished sting is 65536 charectars
    /// \param line The line of the Message__LINE__
    /// \param codeFile The file from wher the messag is writen from __FILE__
    /// \param func The Function  from wher the messag is writen from __func__
    /// \param text the text that will be written
    ///
    void error(int line, std::string codeFile, std::string func, std::string text, ...);
    ///
    /// \brief fatalError writes the text with date and time with FATAL ERROR after the time<br>The maximal length of the finished sting is 65536 charectars
    /// \param line The line of the Message__LINE__
    /// \param codeFile The file from wher the messag is writen from __FILE__
    /// \param func The Function  from wher the messag is writen from __func__
    /// \param text the text that will be written
    ///
    void fatalError(int line, std::string codeFile, std::string func, std::string text, ...);
    ///
    /// \brief warning writes the text with date and time with WARNING after the time<br>The maximal length of the finished sting is 65536 charectars
    /// \param line The line of the Message__LINE__
    /// \param codeFile The file from wher the messag is writen from __FILE__
    /// \param func The Function  from wher the messag is writen from __func__
    /// \param text the text that will be written
    ///
    void warning(int line, std::string codeFile, std::string func, std::string text, ...);
    ///
    /// \brief info writes the text with date and time with INFO after the time<br>The maximal length of the finished sting is 65536 charectars
    /// \param line The line of the Message__LINE__
    /// \param codeFile The file from wher the messag is writen from __FILE__
    /// \param func The Function  from wher the messag is writen from __func__
    /// \param text the text that will be written
    ///
    void info(int line, std::string codeFile, std::string func, std::string text, ...);

    ///
    /// \brief setEndText writes the text with date and time in Cyan when the objekt is deleted and the file will be closed
    /// \param text the text that will be written the standart is "END"
    ///
    void setEndText(std::string text);

    ///
    /// \brief getLogName returns the name of the logfile
    /// \return std::string<br>
    /// 
    /// \par See also:
    /// setLogName()
    ///
    std::string getLogName() const;
    ///
    /// \brief setLogName sets the logfile name
    /// \param value std::string name
    ///
    /// \par See also:
    /// getLogName()
    ///
    void setLogName(const std::string &value);

    ///
    /// \brief getPath returns the pathe to the file<br>
    /// the standart is ""
    /// \return std::string
    /// 
    /// \par See also:
    /// setPath()
    ///
    std::string getPath() const;
    ///
    /// \brief setPath sets the path to the file
    /// \param value std::string
    ///
    /// \par See also:
    /// getPath()
    ///
    void setPath(const std::string &value);


    ///
    /// \brief getStartText returns the start text
    /// \return std::string
    /// 
    /// \par See also:
    /// setStartText()
    ///
    std::string getStartText() const;

    ///
    /// \brief setStartText writes the text without date and time
    /// \param &value the text that will be written
    ///
    /// \par See also:
    /// getStartText()
    ///
    void setStartText(const std::string &value);

    ///
    /// \brief getStarted returns true when started was cald and it was sucsesfull
    /// \return 1 when started
    /// 
    bool getStarted() const;

    ///
    /// \brief getTerminalOut returns true when The messegas should be display on to the std out
    /// \return bool
    /// 
    /// \par See also:
    /// setTerminalOut()
    ///
    bool getTerminalOut() const;

    ///
    /// \brief setTerminalOut sets if the messegas whould writ to the std out(true when it should)
    /// \param &value 
    ///
    /// \par See also:
    /// getTerminalOut()
    ///
    void setTerminalOut(const bool &value);

    ///
    /// \brief getDateFormate returns the date Time formate that is used<br>
    /// the standart is Qt::DateFormat::ISODate
    /// \return time as Qt::DateFormat(https://doc.qt.io/qt-5/qt.html#DateFormat-enum)
    ///
    /// \par See also:
    /// setDateFormate()
    ///
    Qt::DateFormat getDateFormate() const;

    ///
    /// \brief setDateFormate sets the date Time formate that is used<br>
    /// the standart is Qt::DateFormat::ISODate
    /// \param value as Qt::DateFormat(https://doc.qt.io/qt-5/qt.html#DateFormat-enum)
    ///
    /// \par See also:
    /// getDateFormate()
    ///
    void setDateFormate(const Qt::DateFormat &value);

    ///
    /// \brief operator << writes in to the log
    /// \param in const char[]
    ///
    void operator<<(const char in[]);
    ///
    /// \brief operator << writes in to the log
    /// \param in std::string
    ///
    void operator<<(std::string in);
    ///
    /// \brief operator << writes in to the log
    /// \param in int
    ///
    void operator<<(int in);
    ///
    /// \brief operator << writes in to the log
    /// \param in double
    ///
    void operator<<(double in);
    ///
    /// \brief operator << writes in to the log
    /// \param in float
    ///
    void operator<<(float in);
    ///
    /// \brief operator << writes in to the log
    /// \param in bool
    ///
    void operator<<(bool in);
    ///
    /// \brief operator << writes in to the log
    /// \param in FLogger_e
    ///
    void operator<<(FLogger_e in);

private:
    bool line_started = false;

    ///
    /// \brief dateFormate<br>
    /// the standart is Qt::DateFormat::ISODate
    /// dateFormate is the date time formate as Qt::DateFormat(https://doc.qt.io/qt-5/qt.html#DateFormat-enum) that is used and can be set by setDateFormat and looked up by getDateFormate
    ///
    Qt::DateFormat dateFormate = Qt::DateFormat::ISODate;

    ///
    /// \brief stringFormate formats the string<br>The maximal length of the finished sting is 65536 charectars
    /// \param format ist he string to formate
    /// \param args the argumenst that should be inported to the string
    ///
    /// \par See also:
    /// 
    ///
    std::string stringFormate(std::string format, va_list args );

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
    /// \brief StartText is the text at the beginnig of the logfile
    ///
    std::string StartText = "";

    ///
    /// \brief Started
    /// Started is for control that after the start some functions are disabled it is 1 when start was cald
    ///
    bool Started = false;

    ///
    /// \brief logName
    /// logName is the name of the path <br>
    /// the standart is "FLogger"
    ///
    std::string logName = "FQLogger";

    ///
    /// \brief path
    /// path is the location of the file <br>
    /// the standart is ""
    ///
    std::string path = "";

    ///
    /// \brief TerminalOut
    /// TerminalOut controls that the text will only be writen to the std: out whe its true<br>
    /// the standart is true
    ///
    bool TerminalOut = true;
};

}

#endif // FQLOGGER_H
