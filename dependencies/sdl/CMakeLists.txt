message(STATUS "Fetching SDL3...")

FetchContent_Declare(
        sdl3
        GIT_REPOSITORY https://github.com/libsdl-org/SDL/
        GIT_TAG main
)

FetchContent_MakeAvailable(sdl3)

set_property(GLOBAL PROPERTY sdl3_binary_dir "${sdl3_BINARY_DIR}")