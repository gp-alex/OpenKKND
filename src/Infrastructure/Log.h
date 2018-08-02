#pragma once


void log(const char *, ...);


namespace Infrastructure {
    class Log {
    public:
        void Info(const char *foramt, ...);
    };
};
