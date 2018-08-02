#include <stdio.h>
#include <stdarg.h>

#include "src/Infrastructure/Log.h"

#include "src/Infrastructure/PlatformSpecific/OsTools.h"

using Infrastructure::Log;



void log(const char *fmt, ...)
{
    va_list args;

    char msg[4096];

    va_start(args, fmt);
    vsprintf_s(msg, fmt, args);
    va_end(args);

    OsDebugString(msg);
}

void Log::Info(const char *format, ...) {
    va_list args;

    char msg[4096];

    va_start(args, format);
    vsprintf_s(msg, format, args);
    va_end(args);

    OsDebugString(msg);
}