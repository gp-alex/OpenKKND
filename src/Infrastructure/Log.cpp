#include <stdio.h>
#include <stdarg.h>

#include "Infrastructure/Log.h"

using Infrastructure::Log;

void Log::Info(const char *format, ...) {
    va_list args;

    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    printf("\n");
}