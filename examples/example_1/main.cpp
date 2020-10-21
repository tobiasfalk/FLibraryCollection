#include <iostream>
#include <FLibraryCollection/FLogger/FLogger.hpp>

int main(int argc, char *argv[])
{
    //Creating the class
    FLogger::Logger log;
    //creating the cass with log file name and path

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

    //writing to the log with error place
    log.write("place write", __LINE__, __FILE__, __func__);
    log.info("place info", __LINE__, __FILE__, __func__);
    log.warning("place waring", __LINE__, __FILE__, __func__);
    log.error("place error", __LINE__, __FILE__, __func__);
    log.fatalError("place fatal error", __LINE__, __FILE__, __func__);
    return 0;
}
