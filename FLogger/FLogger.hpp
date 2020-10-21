#ifndef FLOGGER_HPP
#define FLOGGER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sys/time.h>

#include <chrono>
#include <ctime>

///
/// The FLogger namespace is where all the FLogger things are
/// the differenz to FLogger curently is that you can set the date time formate and that it is an QObject
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
    ///
    explicit Logger();

    ///
    /// \brief Logger the constructor of the class
    /// \param logName the name of the log
    /// \param path the path wher the log is placed the standerd is ./
    ///
    explicit Logger(std::string logName, std::string path = "./");

    ///
    /// \brief the FLogger destructor
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
    std::string logName = "FLogger";

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

#endif // FLOGGER_HPP
