//
// Created by Robin on 07.05.2024.
//

#ifndef BOOLEANTABLE_LOGGING_H
#define BOOLEANTABLE_LOGGING_H

#include <optional>

#include <spdlog/spdlog.h>

#ifndef NDEBUG
#define DEBUG(...) GetLogger()->debug(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

#define INFO(...) GetLogger()->info(__VA_ARGS__)
#define WARN(...) GetLogger()->warn(__VA_ARGS__)
#define ERROR(...) GetLogger()->error(__VA_ARGS__)
#define CRITICAL(...) GetLogger()->critical(__VA_ARGS__)

spdlog::logger* GetLogger();

#endif //BOOLEANTABLE_LOGGING_H
