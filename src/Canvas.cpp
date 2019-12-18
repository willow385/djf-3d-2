#include <iostream>

#ifndef SDL2_SDL_H
#define SDL2_SDL_H
#include <SDL2/SDL.h>
#endif

#include "Canvas.hpp"

Canvas::Canvas(
    std::string title,
    int width,
    int height
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
        std::cout << "Error in `Canvas::Canvas()`: ";
        std::cout << SDL_GetError() << std::endl;
    }
}

Canvas::~Canvas(void) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(main_window);
    SDL_Quit();
}
