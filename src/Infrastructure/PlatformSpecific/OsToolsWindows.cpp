#include <Windows.h>
#include <Lmcons.h>
#if defined(GetUserName)
    #undef GetUserName
#endif

#include "src/Infrastructure/PlatformSpecific/OsTools.h"


std::string OsGetUserName() {
    wchar_t userName[UNLEN + 1];
    DWORD userNameSize = sizeof(userName) / sizeof(*userName);

    if (GetUserNameW(userName, &userNameSize)) {
        return std::string(userName);
    } else {
        return std::string(constUnknownUser);
    }
}