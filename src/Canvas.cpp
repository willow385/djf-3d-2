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

#ifndef KEYBOARDSTATE_HPP
#define KEYBOARDSTATE_HPP
#include "KeyboardState.hpp"
#endif

#ifndef MODEL3D_HPP
#define MODEL3D_HPP
#include "Model3d.hpp"
#endif

#include "Canvas.hpp"

namespace djf_3d {

Canvas::Canvas(
    const std::string& title,
    const int width,
    const int height
) {
    SDL_Init(SDL_INIT_VIDEO);

    width_px = width;
    height_px = height;

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

int Canvas::get_width(void) {
    return width_px;
}

int Canvas::get_height(void) {
    return height_px;
}

KeyboardState Canvas::get_keyboard_state(void) noexcept {
    KeyboardState result;

    SDL_PumpEvents();
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    result.escape    = (bool) state[SDL_SCANCODE_ESCAPE];
    result.backtick  = (bool) state[SDL_SCANCODE_GRAVE];
    result.dig_1     = (bool) state[SDL_SCANCODE_1];
    result.dig_2     = (bool) state[SDL_SCANCODE_2];
    result.dig_3     = (bool) state[SDL_SCANCODE_3];
    result.dig_4     = (bool) state[SDL_SCANCODE_4];
    result.dig_5     = (bool) state[SDL_SCANCODE_5];
    result.dig_6     = (bool) state[SDL_SCANCODE_6];
    result.dig_7     = (bool) state[SDL_SCANCODE_7];
    result.dig_8     = (bool) state[SDL_SCANCODE_8];
    result.dig_9     = (bool) state[SDL_SCANCODE_9];
    result.dig_0     = (bool) state[SDL_SCANCODE_0];
    result.hyphen    = (bool) state[SDL_SCANCODE_MINUS];
    result.equals    = (bool) state[SDL_SCANCODE_EQUALS];
    result.backspace = (bool) state[SDL_SCANCODE_BACKSPACE];
    result.tab       = (bool) state[SDL_SCANCODE_TAB];
    result.Q         = (bool) state[SDL_SCANCODE_Q];
    result.W         = (bool) state[SDL_SCANCODE_W];
    result.E         = (bool) state[SDL_SCANCODE_E];
    result.R         = (bool) state[SDL_SCANCODE_R];
    result.T         = (bool) state[SDL_SCANCODE_T];
    result.Y         = (bool) state[SDL_SCANCODE_Y];
    result.U         = (bool) state[SDL_SCANCODE_U];
    result.I         = (bool) state[SDL_SCANCODE_I];
    result.O         = (bool) state[SDL_SCANCODE_O];
    result.P         = (bool) state[SDL_SCANCODE_P];
    result.open_bracket = (bool) state[SDL_SCANCODE_LEFTBRACKET];
    result.close_bracket = (bool) state[SDL_SCANCODE_RIGHTBRACKET];
    result.back_slash = (bool) state[SDL_SCANCODE_BACKSLASH];
    result.A         = (bool) state[SDL_SCANCODE_A];
    result.S         = (bool) state[SDL_SCANCODE_S];
    result.D         = (bool) state[SDL_SCANCODE_D];
    result.F         = (bool) state[SDL_SCANCODE_F];
    result.G         = (bool) state[SDL_SCANCODE_G];
    result.H         = (bool) state[SDL_SCANCODE_H];
    result.J         = (bool) state[SDL_SCANCODE_J];
    result.K         = (bool) state[SDL_SCANCODE_K];
    result.L         = (bool) state[SDL_SCANCODE_L];
    result.semicolon = (bool) state[SDL_SCANCODE_SEMICOLON];
    result.quote     = (bool) state[SDL_SCANCODE_APOSTROPHE];
    result.enter     = (bool) state[SDL_SCANCODE_RETURN];
    result.shift     = (bool) (
        state[SDL_SCANCODE_RSHIFT] || state[SDL_SCANCODE_LSHIFT]
    );
    result.Z         = (bool) state[SDL_SCANCODE_Z];
    result.X         = (bool) state[SDL_SCANCODE_X];
    result.C         = (bool) state[SDL_SCANCODE_C];
    result.V         = (bool) state[SDL_SCANCODE_V];
    result.B         = (bool) state[SDL_SCANCODE_B];
    result.N         = (bool) state[SDL_SCANCODE_N];
    result.M         = (bool) state[SDL_SCANCODE_M];
    result.comma     = (bool) state[SDL_SCANCODE_COMMA];
    result.period    = (bool) state[SDL_SCANCODE_PERIOD];
    result.forward_slash = (bool) state[SDL_SCANCODE_SLASH];
    result.ctrl      = (bool) (
        state[SDL_SCANCODE_RCTRL] || state[SDL_SCANCODE_LCTRL]
    );
    result.home      = (bool) state[SDL_SCANCODE_HOME];
    result.alt       = (bool) (
        state[SDL_SCANCODE_RALT] || state[SDL_SCANCODE_LALT]
    );
    result.left_arr  = (bool) state[SDL_SCANCODE_LEFT];
    result.up_arr    = (bool) state[SDL_SCANCODE_UP];
    result.down_arr  = (bool) state[SDL_SCANCODE_DOWN];
    result.right_arr = (bool) state[SDL_SCANCODE_RIGHT];

    return result;
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

void Canvas::draw_model3d(
    const Model3d& model,
    const Perspective& persp
) noexcept {
    int num_verts = model.vertex_cnt();
    if (num_verts == 0) return;
    if (num_verts == 1) {
        SDL_RenderDrawPoint(
            renderer,
            (int) model.nth_vertex(0).project_2d_x(persp),
            (int) model.nth_vertex(0).project_2d_y(persp)
        );
        return;
    }

    for (int i = 0; i < num_verts - 1; i++) {
        SDL_RenderDrawLine(
            renderer,
            (int) model.nth_vertex(i).project_2d_x(persp),
            (int) model.nth_vertex(i).project_2d_y(persp),
            (int) model.nth_vertex(i+1).project_2d_x(persp),
            (int) model.nth_vertex(i+1).project_2d_y(persp)
        );
    }

    SDL_RenderDrawLine(
        renderer,
        (int) model.nth_vertex(num_verts-1).project_2d_x(persp),
        (int) model.nth_vertex(num_verts-1).project_2d_y(persp),
        (int) model.nth_vertex(0).project_2d_x(persp),
        (int) model.nth_vertex(0).project_2d_y(persp)
    );
}

} // end of namespace djf_3d
