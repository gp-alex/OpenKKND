#pragma once

#include <string>

/**
*  \brief Get current operating system user name
*
*  \return user name on success, or constUnknownUser on error
*/
std::string OsGetUserName();

extern const std::string constUnknownUser;