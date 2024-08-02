//
// Created by Robin on 07.05.2024.
//
#include "Logging.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <config.h>

static std::optional<spdlog::logger> logger;

void InitLogger() {
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
#ifndef NDEBUG
    console_sink->set_level(spdlog::level::debug);
#else
    console_sink->set_level(spdlog::level::info);
#endif

    // TODO: Add File Sink

    logger = spdlog::logger(PROJECT_NAME, {console_sink});
#ifndef NDEBUG
    console_sink->set_level(spdlog::level::debug);
    logger.value().set_level(spdlog::level::debug);
#else
    console_sink->set_level(spdlog::level::info);
#endif
}

spdlog::logger* GetLogger() {
    return &logger.value();
}
