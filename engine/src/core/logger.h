#pragma once 
#include "defines.h"

#define   LOG_WARN_ENABLED 1
#define   LOG_INFO_ENABLED 1
#define   LOG_DEBUG_ENABLED 1 
#define   LOG_TRACE_ENABLED 1

// disable debug and trace logging for release builds
#if EPHRELEASE == 1
#define LOG_DEBUG_ENABLED 0
#define LOG_TRACE_ENABLED 0
#endif

typedef enum log_level {
    LOG_LEVEL_FATAL = 0,
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_WARN = 2,
    LOG_LEVEL_INFO = 3,
    LOG_LEVEL_DEBUG = 4,
    LOG_LEVEL_TRACE = 5,
} log_level; 

b8 initialize_logging();
void shutdown_logging();

EPHAPI void log_output(log_level level, const char* message, ...);

// logs a fatal-level message
#define EPHFATAL(message, ...) log_output(LOG_LEVEL_FATAL, message, ##__VA_ARGS__);

#ifndef EPHERROR
// logs an error-level message
#define EPHERROR(message, ...) log_output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__);
#endif

#if LOG_WARN_ENABLED == 1
// logs a warning-level message
#define EPHWARN(message, ...) log_output(LOG_LEVEL_WARN, message, ##__VA_ARGS__);
#else
// does nothing when LOG_WARN_ENABLED != 1
#define EPHWARN(message, ...);
#endif

#if LOG_INFO_ENABLED == 1
// logs a info-level message
#define EPHINFO(message, ...) log_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__);
#else
// does nothing when LOG_INFO_ENABLED != 1
#define EPHINFO(message, ...);
#endif

#if LOG_DEBUG_ENABLED == 1
// logs a debug-level message
#define EPHDEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__);
#else
// does nothing when LOG_DEBUG_ENABLED != 1
#define EPHDEBUG(message, ...);
#endif

#if LOG_TRACE_ENABLED == 1
// logs a trace-level message
#define EPHTRACE(message, ...) log_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__);
#else
// does nothing when LOG_TRACE_ENABLED != 1
#define EPHTRACE(message, ...);
#endif