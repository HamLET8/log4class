### The log4class is convinient way to use log4cpp, which provides six api to use.
    logError("The log is error message");
    logCrit("The log is crit message");
    logDebug("The log is debug message");
    logInfo("The log is info message");
    logFatal("The log is fatal message");
    logWarn("The log is warn message");
    
install log4cpp ,include log4class.hh header and compile with log4class.cpp file
compile way: 
``` 
g++ *.cpp -o main -llog4cpp -lpthread 
```

### it will put the smessage into "logfile.log" file, and the config of log4class follows:

layout:PatternLayout. output fomat: ("%d: %p %c %x: %m%n")
```
2022-10-07 12:34:46,977: WARN  : The log is warn message	 File: argvar.cpp	 Line: 24	 Func: main
2022-10-07 12:34:46,977: INFO  : The log is info message	 File: argvar.cpp	 Line: 11	 Func: func
```
appender:RollingFileAppender. 10 backup file ,each have 5 kB;
priority: debug

# next mission: format input and output
