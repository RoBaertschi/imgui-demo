message(STATUS "Fetching glad...")

FetchContent_Declare(
        glad
        GIT_REPOSITORY https://github.com/Dav1dde/glad
        GIT_TAG v2.0.6
)

FetchContent_MakeAvailable(
        glad
)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${glad_SOURCE_DIR}/cmake")

set(
        GLAD_CMAKE_DIR "${glad_SOURCE_DIR}/cmake"
        CACHE STRING "Directory containing glad generator CMakeLists.txt. Must be absolute."
)

set(
        GLAD_SOURCES_DIR "${glad_SOURCE_DIR}"
        CACHE STRING "Directory containing glad sources (python modules), used as working directory. Must be absolute."
)
mark_as_advanced(GLAD_CMAKE_DIR)

find_package(glad REQUIRED CONFIG)

glad_add_library(glad_opengl LANGUAGE C API gl:core=4.5)
add_library(glad::opengl ALIAS glad_opengl)