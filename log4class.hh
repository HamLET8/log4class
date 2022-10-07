#pragma once
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <string>

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


void log_fatal(const char *msg, const char *fileName, const int Line, const char *FuncName);
void log_crit(const char *msg, const char *fileName, const int Line, const char *FuncName);
void log_warn(const char *msg, const char *fileName, const int Line, const char *FuncName);
void log_error(const char *msg, const char *fileName, const int Line, const char *FuncName);
void log_debug(const char *msg, const char *fileName, const int Line, const char *FuncName);
void log_info(const char *msg, const char *fileName, const int Line, const char *FuncName);

#define logError(msg) log_fatal(msg, __FILE__, __LINE__, __func__)
#define logCrit(msg) log_crit(msg, __FILE__, __LINE__, __func__)
#define logWarn(msg) log_warn(msg, __FILE__, __LINE__, __func__)
#define logInfo(msg) log_info(msg, __FILE__, __LINE__, __func__)
#define logDebug(msg) log_debug(msg, __FILE__, __LINE__, __func__)
#define logFatal(msg) log_error(msg, __FILE__, __LINE__, __func__)





