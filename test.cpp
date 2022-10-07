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
	
//log->info("The log is info message");
    logError("The log is error message");
    logCrit("The log is crit message");
    logDebug("The log is debug message");
    logInfo("The log is info message");
    logFatal("The log is fatal message");
    logWarn("The log is warn message");

    func();
//log->fatal("The log is fatal message");
//log->crit("The log is crit message");

return 0;
}
