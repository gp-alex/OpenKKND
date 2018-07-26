#include <pwd.h>
#include <unistd.h>
#include <stdio.h>

#include <sys/types.h>

#include "src/Infrastructure/PlatformSpecific/OsTools.h"


std::string OsGetUserName() {
    struct passwd *pd = getpwuid(getuid());
    if (pd == nullptr) {
        return std::string(constUnknownUser);
    } else {
        return std::string(pd->pw_name);
    }
}

void OsDebugString(const char *str) {
    printf("%s\n", str);
}


void OsInitConsole() {
}