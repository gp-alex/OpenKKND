#include <stdio.h>
#include <direct.h>

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

std::string OsGetCurrentDirectory() {
    char buffer[MAX_PATH + 1];

    return std::string(
        _getcwd(buffer, sizeof(buffer))
    );
}

std::string OsGetCommandLine() {
    return std::string(
        GetCommandLineA()
    );
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

unsigned long OsGetPrecisionTime() {
    return timeGetTime();
}

unsigned int OsGetTime() {
    return GetTickCount();
}

void OsShowCursor(bool show) {
    ShowCursor((BOOL)show);
}

void OsThreadSleep(int ms) {
    Sleep((DWORD)ms);
}

void OsGetApplicationConfig(
    char *installation_drive_letter,
    bool *is_minimal_install,
    char *game_data_installation_dir
) {
    DWORD cbData; // [sp+8h] [bp-1Ch]@2
    HKEY phkResult; // [sp+Ch] [bp-18h]@1
    DWORD Type; // [sp+10h] [bp-14h]@2
    BYTE Data[16]; // [sp+14h] [bp-10h]@4

    *installation_drive_letter = 'C';
    *is_minimal_install = 1;
    strcpy(game_data_installation_dir, ".");

    if (!RegOpenKeyExA(
        HKEY_LOCAL_MACHINE,
        "SOFTWARE\\Melbourne House\\Krush, Kill 'n' Destroy Xtreme\\1.00.000",
        0,
        0x20019u,
        &phkResult))
    {
        cbData = 256;
        if (!RegQueryValueExA(phkResult, "GamePath", 0, &Type, (LPBYTE)game_data_installation_dir, &cbData)) {
            game_data_installation_dir[cbData] = 0;
        }

        cbData = sizeof(Data);
        if (!RegQueryValueExA(phkResult, "DriveLetter", 0, &Type, Data, &cbData)) {
            *installation_drive_letter = Data[0];
        }

        cbData = 4;
        int installation_type = 0;
        if (!RegQueryValueExA(phkResult, "MinimumInstall", 0, &Type, (LPBYTE)&installation_type, &cbData) {
            *is_minimal_install = installation_type != 0;
        }

        RegCloseKey(phkResult);
    }
}