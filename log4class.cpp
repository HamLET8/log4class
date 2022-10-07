#include "log4class.hh"

Mylogger::Mylogger()
:Mylogger("%d: %p %c %x: %m%n")
{
}

Mylogger::Mylogger(const char *conf)
:confPTL(conf), root(log4cpp::Category::getRoot())
{

    log4cpp::PatternLayout* ppl = new log4cpp::PatternLayout();
    ppl->setConversionPattern(confPTL);

    log4cpp::RollingFileAppender* rfa = new log4cpp::RollingFileAppender("RollingFileAppender", "logfile.log", 5*1024, 10);
    rfa->setLayout(ppl);

    root.setPriority(log4cpp::Priority::DEBUG);
    root.addAppender(rfa);
}

Mylogger* Mylogger::instance = nullptr;
Mylogger *logger = Mylogger::getInstance();

Mylogger::~Mylogger(){
    delete instance;
    log4cpp::Category::shutdown();
}
Mylogger* Mylogger::getInstance(){
        if(instance == nullptr){
            instance =  new Mylogger();
        }
        return instance; 
}
void Mylogger::fatal(const char* msg){
    root.fatal(msg);
}
void Mylogger::crit(const char* msg){
    root.crit(msg);
}
void Mylogger::warn(const char* msg){
    root.warn(msg);
}
void Mylogger::error(const char* msg){
    root.error(msg);
}
void Mylogger::debug(const char* msg){
    root.debug(msg);
}
void Mylogger::info(const char* msg){
    root.info(msg);
}

void log_error(const char *msg, const char *fileName, const int Line, const char *FuncName){
    std::string msg_a(msg);
    std::string msgs =  std::string(msg) + "\t File: " + fileName + "\t Line: " + std::to_string(Line) + "\t Func: " + FuncName;
    logger->error(msgs.c_str());
}

void log_crit(const char *msg, const char *fileName, const int Line, const char *FuncName){
    std::string msg_a(msg);
    std::string msgs =  std::string(msg) + "\t File: " + fileName + "\t Line: " + std::to_string(Line) + "\t Func: " + FuncName;
    logger->crit(msgs.c_str());
}

void log_debug(const char *msg, const char *fileName, const int Line, const char *FuncName){
    std::string msg_a(msg);
    std::string msgs =  std::string(msg) + "\t File: " + fileName + "\t Line: " + std::to_string(Line) + "\t Func: " + FuncName;
    logger->debug(msgs.c_str());
}

void log_warn(const char *msg, const char *fileName, const int Line, const char *FuncName){
    std::string msg_a(msg);
    std::string msgs =  std::string(msg) + "\t File: " + fileName + "\t Line: " + std::to_string(Line) + "\t Func: " + FuncName;
    logger->warn(msgs.c_str());
}

void log_info(const char *msg, const char *fileName, const int Line, const char *FuncName){
    std::string msg_a(msg);
    std::string msgs =  std::string(msg) + "\t File: " + fileName + "\t Line: " + std::to_string(Line) + "\t Func: " + FuncName;
    logger->info(msgs.c_str());
}

void log_fatal(const char *msg, const char *fileName, const int Line, const char *FuncName){
    std::string msg_a(msg);
    std::string msgs =  std::string(msg) + "\t File: " + fileName + "\t Line: " + std::to_string(Line) + "\t Func: " + FuncName;
    logger->fatal(msgs.c_str());
}

