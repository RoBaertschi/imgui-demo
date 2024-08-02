include(FetchContent)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

add_subdirectory(sdl)
add_subdirectory(imgui)
add_subdirectory(glad)
add_subdirectory(fmtlib)
add_subdirectory(spdlog)