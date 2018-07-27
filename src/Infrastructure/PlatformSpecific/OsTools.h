#pragma once

#include <string>

/**
*  \brief Get current operating system user name
*
*  \return user name on success, or constUnknownUser on error
*/
std::string OsGetUserName();
std::string OsGetCurrentDirectory();

void OsInitTimer();
void OsInitConsole();

/**
*  \brief Output string to stdin, DebugOutput and any other available sink
*/
void OsDebugString(const char *str);

extern const std::string constUnknownUser;