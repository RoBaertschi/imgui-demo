//
// Created by Robin on 07.05.2024.
//

#ifndef BOOLEANTABLE_WINDOW_H
#define BOOLEANTABLE_WINDOW_H

#include <stdexcept>


#include <SDL3/SDL.h>
#include <glad/gl.h>
#include <imgui.h>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_opengl3.h>

const int cWinHeight = 400;
const int cWinWidth = 600;

class CWindow {
    SDL_Window* window;
    SDL_GLContext context;

    bool running = true;

public:
    explicit CWindow();
    ~CWindow();

    void run();
};


#endif //BOOLEANTABLE_WINDOW_H
