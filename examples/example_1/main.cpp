#include <iostream>
#include <FLibraryCollection/FLogger/FLogger.hpp>

int main(int argc, char *argv[])
{
    //Creating the class
    FLogger::Logger log;
    //creating the cass with log file name and path
    //FLogger::Logger log("log_example_1", "logs/");

    //seting up all the parameters
    log.setLogName("log_example_1");    //Here the name of the Log file will be set the time of creation will be writen in front
    log.setPath("logs/");               //Here the path to the Log file will be set if you want the file to be in the main folder leaf it empty
    log.setStartText("Start Text");     //Here the text that will be writen at the beginging of the log is set if you don't call it it will be empty
    log.setEndText("End Text");         //Here the text that will be writen at the beginging of the log is set if you don't call it it will be END
    
    //starting the logfile
    log.start();                        //Here the file will be created and opend and all the functions that were caled in the setup will have no effect

    //writing to the log simply
    log.write("normal write");
    log.info("normal info");
    log.warning("normal waring");
    log.error("normal error");
    log.fatalError("normal fatal error");

    //writing to the log in printf style
    log.write("normal write %s", "in printf style");
    log.info("normal info %s", "in printf style");
    log.warning("normal waring %s", "in printf style");
    log.error("normal error %s", "in printf style");
    log.fatalError("normal fatal error %s", "in printf style");

    //writing to the log with error place
    log.write(__LINE__, __FILE__, __func__, "place write");
    log.info(__LINE__, __FILE__, __func__, "place info");
    log.warning(__LINE__, __FILE__, __func__, "place waring");
    log.error(__LINE__, __FILE__, __func__, "place error");
    log.fatalError(__LINE__, __FILE__, __func__, "place fatal error");

    //writing to the log with error place
    log.write(__LINE__, __FILE__, __func__, "place write %s", "in printf style");
    log.info(__LINE__, __FILE__, __func__, "place info %s", "in printf style");
    log.warning(__LINE__, __FILE__, __func__, "place waring %s", "in printf style");
    log.error(__LINE__, __FILE__, __func__, "place error %s", "in printf style");
    log.fatalError(__LINE__, __FILE__, __func__, "place fatal error %s", "in printf style");

    //writing to the log in c++ style
    std::string a = "std string ";
    log << a;
    log << "const char[] ";
    log << " int: ";
    log << 23;
    log << " floate(double): ";
    log << 3.14;
    log << " bool: ";
    log << false;
    log << " log entry end: ";
    log << FLogger::FLogger_e::end;
    return 0;
}
