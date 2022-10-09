#pragma once
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <string>
#include <utility>
#define __MAX_LINE_LENS__ 100

class Mylogger
{
public:
    static Mylogger * getInstance();
	void fatal(const char *msg);
	void crit(const char *msg);
	void warn(const char *msg);
	void error(const char *msg);
	void debug(const char *msg);
	void info(const char *msg);
	
private:
	
    Mylogger();
    Mylogger(const char*);
	~Mylogger();
    
private:
    static Mylogger* instance;
    log4cpp::Category& root;
    std::string confPTL;
};


void log_fatal( std::string&& msg, const char *fileName, const int Line, const char *FuncName);
void log_crit( std::string&& msg, const char *fileName, const int Line, const char *FuncName);
void log_warn( std::string&& msg, const char *fileName, const int Line, const char *FuncName);
void log_error(std::string&& msg, const char *fileName, const int Line, const char *FuncName);
void log_debug(std::string&& msg, const char *fileName, const int Line, const char *FuncName);
void log_info( std::string&& msg, const char *fileName, const int Line, const char *FuncName);

#define logError(args...) log_error((log_fmt(args)), __FILE__, __LINE__, __func__) //record current file,line,and function
#define logCrit(args...)  log_crit(( log_fmt(args)), __FILE__, __LINE__, __func__)
#define logWarn(args...)  log_warn(( log_fmt(args)), __FILE__, __LINE__, __func__)
#define logInfo(args...)  log_info(( log_fmt(args)), __FILE__, __LINE__, __func__)
#define logDebug(args...) log_debug((log_fmt(args)), __FILE__, __LINE__, __func__)
#define logFatal(args...) log_fatal((log_fmt(args)), __FILE__, __LINE__, __func__)


template<typename...Args>
std::string log_fmt(const char* fmt, Args...args){ //get a format string ,then send to log 
	
	char nfmt[__MAX_LINE_LENS__] = {0};; //max number of  a format string 	
	sprintf(nfmt, fmt, args...);
	
	std::string fmt_temp(nfmt);
	return fmt_temp;
}


