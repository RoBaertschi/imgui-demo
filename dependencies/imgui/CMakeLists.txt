message(STATUS "Fetching imgui...")

FetchContent_Declare(
        imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui
        GIT_TAG v1.91.0-docking
)

FetchContent_MakeAvailable(imgui)

set(SRCS ${imgui_SOURCE_DIR}/imgui.cpp
        ${imgui_SOURCE_DIR}/imgui_demo.cpp
        ${imgui_SOURCE_DIR}/imgui_draw.cpp
        ${imgui_SOURCE_DIR}/imgui_tables.cpp
        ${imgui_SOURCE_DIR}/imgui_widgets.cpp
        ${imgui_SOURCE_DIR}/imstb_rectpack.h
        ${imgui_SOURCE_DIR}/imstb_textedit.h
        ${imgui_SOURCE_DIR}/imstb_truetype.h
        ${imgui_SOURCE_DIR}/imgui.h
        ${imgui_SOURCE_DIR}/imgui_internal.h
        ${CMAKE_CURRENT_SOURCE_DIR}/imconfig.h
)

add_library(imgui STATIC ${SRCS})
target_include_directories(imgui PUBLIC ${imgui_SOURCE_DIR})
target_include_directories(imgui PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(imgui PUBLIC IMGUI_DEFINE_MATH_OPERATORS)
add_library(imgui::imgui ALIAS imgui)

add_library(imgui_sdl3 STATIC ${imgui_SOURCE_DIR}/backends/imgui_impl_sdl3.cpp ${imgui_SOURCE_DIR}/backends/imgui_impl_sdl3.h)
target_include_directories(imgui_sdl3 PUBLIC ${imgui_SOURCE_DIR}/backends)
target_link_libraries(imgui_sdl3 imgui::imgui SDL3::SDL3)
add_library(imgui::sdl3 ALIAS imgui_sdl3)

add_library(imgui_opengl3 STATIC ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.h)
target_include_directories(imgui_sdl3 PUBLIC ${imgui_SOURCE_DIR}/backends)
target_link_libraries(imgui_opengl3 imgui::imgui SDL3::SDL3)
add_library(imgui::opengl3 ALIAS imgui_opengl3)
