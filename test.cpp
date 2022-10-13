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
    auto start = std::chrono::steady_clock::now();    

    const char * str = "this is a string.";  
    for(int i = 0; i < 10; ++i){
    
        logError("The log is error message %s", str);
        logCrit( "The log is crit message %s", str);
        logDebug("The log is debug message %s", str);
        logInfo( "The log is info message %s", str);
        logWarn( "The log is warn message %s", str);

        logFatal("The log is fatal message!  %s", str);
    }
   
    auto end = std::chrono::steady_clock::now();
    auto time_used = end - start ;
    cout << "cost time: " << time_used.count()  << "ns" << " = " << (time_used.count() /1000) <<"us"<< std::endl;
  //  func();

    return 0;
}
