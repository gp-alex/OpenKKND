#include <stdio.h>

#include <Windows.h>
#include <Lmcons.h>
#if defined(GetUserName)
    #undef GetUserName
#endif

#include <locale>
#include <sstream>

#include "src/Infrastructure/PlatformSpecific/OsTools.h"


std::string OsGetUserName() {
    wchar_t userName[UNLEN + 1];
    DWORD userNameSize = sizeof(userName) / sizeof(*userName);

    if (GetUserNameW(userName, &userNameSize)) {
        std::ostringstream ss;
        const wchar_t *i = userName;
        ss << std::use_facet<std::ctype<wchar_t>>(std::locale()).narrow(*i++, '?');
        return ss.str();
    } else {
        return std::string(constUnknownUser);
    }
}


void OsDebugString(const char *str) {
    printf("%s\n", str);
    OutputDebugStringA(str);
}


void OsInitConsole() {
    if (AllocConsole()) {
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
    }
}

void OsInitTimer() {
    timeBeginPeriod(1u);
}