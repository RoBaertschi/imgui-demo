configure_file(config.h.in config.h)

add_executable(imgui-demo main.cpp
        Window.cpp
        Window.h
        Logging.h
        Logging.cpp
        )
target_link_libraries(imgui-demo PRIVATE
        imgui::imgui imgui::opengl3 imgui::sdl3 # imgui
        SDL3::SDL3 # windowing
        glad::opengl # opengl loader
        spdlog::spdlog # logger
        fmt::fmt # formating
)

target_include_directories(
        imgui-demo PUBLIC
        "${CMAKE_CURRENT_BINARY_DIR}"
)

# Copy the SDL3.dll to the project directory

get_property(sdl3_BINARY_DIR GLOBAL PROPERTY sdl3_binary_dir)

add_custom_target(sdl-copy-dll)
if (${WIN32})
        add_custom_command(
                TARGET sdl-copy-dll
                POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${sdl3_BINARY_DIR}/SDL3.dll"
                $<TARGET_FILE_DIR:imgui-demo>
        )
endif ()

add_dependencies(imgui-demo sdl-copy-dll)
add_dependencies(sdl-copy-dll SDL3::SDL3)
