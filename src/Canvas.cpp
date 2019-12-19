#include <stdexcept>
#include <iostream>

#ifndef SDL2_SDL_H
#define SDL2_SDL_H
#include <SDL2/SDL.h>
#endif

#include "Canvas.hpp"

Canvas::Canvas(
    const std::string title,
    const int width,
    const int height
) {
    SDL_Init(SDL_INIT_VIDEO);

    main_window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        0
    );

    renderer = SDL_CreateRenderer(
        main_window,
        0,
        0
    );

    if (!main_window || !renderer) {
        std::cerr << "Error in Canvas::Canvas(): "
            << SDL_GetError()
            << std::endl;
        throw std::exception();
    }

    std::cout
        << "Click the close button or press the X key to exit"
        << std::endl;

}

Canvas::~Canvas(void) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(main_window);
    SDL_Quit();
}

void Canvas::refresh(void) {
    SDL_RenderPresent(renderer);
}

bool Canvas::exit(void) {
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            return true;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_x) {
                return true;
            }
    }

    return false;
}

void Canvas::set_draw_color(
    const int r,
    const int g,
    const int b
) {
    SDL_SetRenderDrawColor(
        renderer,
        r,
        g,
        b,
        0
    );
}

void Canvas::draw_point(const int x, const int y) {
    SDL_RenderDrawPoint(
        renderer,
        x,
        y
    );
}

void Canvas::draw_line(
    const int x0,
    const int y0,
    const int x1,
    const int y1
) {
    SDL_RenderDrawLine(
        renderer,
        x0,
        y0,
        x1,
        y1
    );
}

void Canvas::fill_window(void) {
    SDL_RenderClear(renderer);
}
