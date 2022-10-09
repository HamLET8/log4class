#include <cstdarg>
#include <iostream>
#include "log4class.hh"


using std::cout;
using std::string;
using namespace log4cpp;


void func(){
    logInfo("The log is info message");
}


int main()
{
    logError("The ");
    logCrit("The log is crit message");
    logDebug("The log is debug message");
    logInfo("The log is info message");
    logWarn("The log is warn message");
    
    const char*  usr  =  "li";
    logFatal("The log is fatal message! usr : %s", usr);
    
    func();

    return 0;
}
