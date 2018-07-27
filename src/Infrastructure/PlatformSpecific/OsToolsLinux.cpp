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

std::string OsGetCurrentDirectory() {
    char buffer[SIZE + 1];

    char *answer = getcwd(buffer, sizeof(buffer));
    if (!answer) {
        answer = "";
    }

    return std::string(answer);
}

void OsDebugString(const char *str) {
    printf("%s\n", str);
}


void OsInitConsole() {
}