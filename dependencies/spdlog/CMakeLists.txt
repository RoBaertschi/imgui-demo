message(STATUS "Fetching spdlog...")

FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog/
        GIT_TAG v1.14.1
)

set(SPDLOG_FMT_EXTERNAL ON)
FetchContent_MakeAvailable(spdlog)