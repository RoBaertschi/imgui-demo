//
// Created by Robin on 07.05.2024.
//
#include "Logging.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <config.h>

static struct SGlobalLogger {
    SGlobalLogger() {
#ifndef NDEBUG
        console_sink->set_level(spdlog::level::debug);
        logger.set_level(spdlog::level::debug);
#else
        console_sink->set_level(spdlog::level::info);
        logger.set_level(spdlog::level::info);
#endif
    }

    std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    spdlog::logger logger{PROJECT_NAME, {console_sink}};


} global_logger;


spdlog::logger* GetLogger() {
    return &global_logger.logger;
}
