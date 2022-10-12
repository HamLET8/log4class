#include <cstdarg>
#include <iostream>
#include <chrono>
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

    auto start = std::chrono::steady_clock::now();    
    const char*  usr  =  "li";
    logFatal("The log is fatal message! usr : %s", usr);
    auto end = std::chrono::steady_clock::now();
    
    auto time_used = end - start ;

    cout << "cost time: " << time_used.count()  << "ns" << std::endl;
    func();

    return 0;
}
