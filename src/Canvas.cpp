#ifndef STDEXCEPT
#define STDEXCEPT
#include <stdexcept>
#endif

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef SDL2_SDL_H
#define SDL2_SDL_H
#include <SDL2/SDL.h>
#endif

#ifndef COORDPAIR_HPP
#define COORDPAIR_HPP
#include "CoordPair.hpp"
#endif

#ifndef COORDTRIPLE_HPP
#define COORDTRIPLE_HPP
#include "CoordTriple.hpp"
#endif

#ifndef PERSPECTIVE_HPP
#define PERSPECTIVE_HPP
#include "Perspective.hpp"
#endif

#include "Canvas.hpp"

namespace djf_3d {

Canvas::Canvas(
    const std::string& title,
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

Canvas::~Canvas(void) noexcept {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(main_window);
    SDL_Quit();
}

void Canvas::refresh(void) noexcept {
    SDL_RenderPresent(renderer);
}

bool Canvas::exit(void) noexcept {
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
) noexcept {
    SDL_SetRenderDrawColor(
        renderer,
        r,
        g,
        b,
        0
    );
}

void Canvas::draw_point(
    const int x,
    const int y
) noexcept {
    SDL_RenderDrawPoint(
        renderer,
        x,
        y
    );
}

void Canvas::draw_point(
    const CoordPair& point
) noexcept {
    SDL_RenderDrawPoint(
        renderer,
        (int) point.get_x_pos(),
        (int) point.get_y_pos()
    );
}

void Canvas::draw_point(
    const CoordTriple& point,
    const CoordPair& vanish_point,
    const float fov
) noexcept {
    SDL_RenderDrawPoint(
        renderer,
        (int) point.project_2d_x(
            (int) vanish_point.get_x_pos(),
            fov
        ),
        (int) point.project_2d_y(
            (int) vanish_point.get_y_pos(),
            fov
        )
    );
}

void Canvas::draw_point(
    const CoordTriple& point,
    const Perspective& perspective
) noexcept {
    CoordPair projection_2d
        = point.project_2d(perspective);
    SDL_RenderDrawPoint(
        renderer,
        (int) projection_2d.get_x_pos(),
        (int) projection_2d.get_y_pos()
    );
}

void Canvas::draw_line(
    const int x0,
    const int y0,
    const int x1,
    const int y1
) noexcept {
    SDL_RenderDrawLine(
        renderer,
        x0,
        y0,
        x1,
        y1
    );
}

void Canvas::draw_line(
    const CoordPair& point_0,
    const CoordPair& point_1
) noexcept {
    SDL_RenderDrawLine(
        renderer,
        (int) point_0.get_x_pos(),
        (int) point_0.get_y_pos(),
        (int) point_1.get_x_pos(),
        (int) point_1.get_y_pos()
    );
}

void Canvas::draw_line(
    const CoordTriple& point_0,
    const CoordTriple& point_1,
    const Perspective& perspective
) noexcept {
    CoordPair point_0_2d
        = point_0.project_2d(perspective);
    CoordPair point_1_2d
        = point_1.project_2d(perspective);
    SDL_RenderDrawLine(
        renderer,
        (int) point_0_2d.get_x_pos(),
        (int) point_0_2d.get_y_pos(),
        (int) point_1_2d.get_x_pos(),
        (int) point_1_2d.get_y_pos()
    );
}

void Canvas::fill_window(void) noexcept {
    SDL_RenderClear(renderer);
}

} // end of namespace djf_3d
