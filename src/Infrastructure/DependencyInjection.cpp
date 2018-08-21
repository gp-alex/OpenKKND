#include "Infrastructure/DependencyInjection.h"

using Infrastructure::DependencyInjection;
using Infrastructure::Log;

std::shared_ptr<Log> DependencyInjection::log = nullptr;