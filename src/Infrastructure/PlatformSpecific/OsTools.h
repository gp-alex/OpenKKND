#pragma once

#include <string>

/**
*  \brief Get current operating system user name
*
*  \return user name on success, or constUnknownUser on error
*/
std::string OsGetUserName();
std::string OsGetCurrentDirectory();
std::string OsGetCommandLine();

void OsInitConsole();

void OsInitTimer();
unsigned long OsGetPrecisionTime();
unsigned int OsGetTime();

void OsThreadSleep(int ms);

void OsGetApplicationConfig(
    char *installation_drive_letter,
    bool *is_minimal_install,
    char *game_data_installation_dir
);

/**
*  \brief Output string to stdin, DebugOutput and any other available sink
*/
void OsDebugString(const char *str);

void OsShowCursor(bool show);

extern const std::string constUnknownUser;