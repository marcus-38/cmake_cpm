#include <spdlog/spdlog.h>

#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"
#include <cstdio>
#include <SDL3/SDL.h>
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <SDL3/SDL_opengles2.h>
#else
#include <SDL3/SDL_opengl.h>
#endif

int main() {
    spdlog::info("Using spdlog to work with messages to the user");

    // setup SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        spdlog::error("SDL_Init(): ", SDL_GetError());
        return -1;
    }
    spdlog::info("SDL_Init() successful");

    // create a window with SDL_Renderer graphics context
    constexpr Uint32 windowFlags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN;
    SDL_Window *window = SDL_CreateWindow("Change my name", 1280, 720, windowFlags);
    if (window == nullptr) {
        spdlog::error("SDL_CreateWindow(): ", SDL_GetError());
        return -1;
    }
    spdlog::info("SDL_CreateWindow() successful");
    SDL_Renderer *renderer = SDL_CreateRenderer(window, nullptr);
    SDL_SetRenderVSync(renderer, 1);
    if (renderer == nullptr) {
        spdlog::error("SDL_CreateRenderer(): ", SDL_GetError());
        return -1;
    }
    spdlog::info("SDL_CreateRenderer() successful");
    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    SDL_ShowWindow(window);

    // setup platform/renderer backends

    // state
    auto clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // main loop
    bool done = false;
    while (!done) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                spdlog::info("Detected quit event");
                done = true;
            }
            if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED) {
                spdlog::info("Detected close event");
                done = true;
            }
        }
        if (SDL_GetWindowFlags(window) & SDL_WINDOW_MINIMIZED) {
            SDL_Delay(10);
            continue;
        }

        // rendering
        SDL_SetRenderDrawColorFloat(renderer, clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    } // end of main loop

    // cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}