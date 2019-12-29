#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "CoordPair.h"
#include "CoordTriple.h"
#include "Perspective.h"
#include "KeyboardState.h"
#include "Model3d.h"
#include "Color.h"
#include "Scene.h"
#include "Canvas.h"

namespace djf_3d {

Canvas::Canvas(
    const std::string& title,
    const int width,
    const int height
) {
    std::cout <<
        "Calling ctor djf_3d::Canvas::Canvas()... ";

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

    /* We have to use malloc() here because SDL is
       written in C. */
    event = (SDL_Event *) std::malloc(sizeof(SDL_Event));

    if (!main_window || !renderer) {
        std::cerr
            << "failed.\nError in djf_3d::Canvas::Canvas()"
            << ": "
            << SDL_GetError()
            << std::endl;
        throw std::exception();
    }

    if (!event) {
        std::cerr
            << "failed.\nError in djf_3d::Canvas::Canvas()"
            << ": unsuccessful call to std::malloc() when "
            << "trying to allocate memory for SDL_Event "
            << "*event"
            << std::endl;
        throw std::exception();
    }

    std::cout
        << "success."
        << std::endl;

}

Canvas::~Canvas(void) noexcept {
    std::cout
        << "Calling dtor djf_3d::Canvas::~Canvas()... ";
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(main_window);
    std::free(event);
    SDL_Quit();
    std::cout << "done." << std::endl;
}

void Canvas::refresh(void) noexcept {
    SDL_RenderPresent(renderer);
}

bool Canvas::exit(void) noexcept {
    SDL_PollEvent(event);
    switch (event->type) {
        case SDL_QUIT:
            return true;
    }

    return false;
}

int Canvas::get_width(void) const noexcept {
    return width_px;
}

int Canvas::get_height(void) const noexcept {
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
    result.open_bracket
        = (bool) state[SDL_SCANCODE_LEFTBRACKET];
    result.close_bracket
        = (bool) state[SDL_SCANCODE_RIGHTBRACKET];
    result.back_slash
        = (bool) state[SDL_SCANCODE_BACKSLASH];
    result.A         = (bool) state[SDL_SCANCODE_A];
    result.S         = (bool) state[SDL_SCANCODE_S];
    result.D         = (bool) state[SDL_SCANCODE_D];
    result.F         = (bool) state[SDL_SCANCODE_F];
    result.G         = (bool) state[SDL_SCANCODE_G];
    result.H         = (bool) state[SDL_SCANCODE_H];
    result.J         = (bool) state[SDL_SCANCODE_J];
    result.K         = (bool) state[SDL_SCANCODE_K];
    result.L         = (bool) state[SDL_SCANCODE_L];
    result.semicolon
        = (bool) state[SDL_SCANCODE_SEMICOLON];
    result.quote
        = (bool) state[SDL_SCANCODE_APOSTROPHE];
    result.enter     = (bool) state[SDL_SCANCODE_RETURN];
    result.shift     = (bool) (
        state[SDL_SCANCODE_RSHIFT]
    ||
        state[SDL_SCANCODE_LSHIFT]
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
    result.forward_slash
        = (bool) state[SDL_SCANCODE_SLASH];
    result.ctrl      = (bool) (
        state[SDL_SCANCODE_RCTRL]
    ||
        state[SDL_SCANCODE_LCTRL]
    );
    result.home      = (bool) state[SDL_SCANCODE_HOME];
    result.alt       = (bool) (
        state[SDL_SCANCODE_RALT]
    ||
        state[SDL_SCANCODE_LALT]
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
    const int b,
    const int alpha
) noexcept {
    SDL_SetRenderDrawColor(
        renderer,
        r,
        g,
        b,
        alpha
    );
}

void Canvas::set_draw_color(const Color& color) noexcept {
    SDL_SetRenderDrawColor(
        renderer,
        (int) color.red,
        (int) color.green,
        (int) color.blue,
        (int) color.alpha
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

void Canvas::draw_scene(
    const Scene& scene,
    const Perspective& persp
) noexcept {
    size_t model_cnt = scene.model_cnt();
    size_t point_2d_cnt = scene.point_2d_cnt();
    size_t point_3d_cnt = scene.point_3d_cnt();

    for (size_t i = 0; i < model_cnt; i++) {
        this->draw_model3d(
            scene.nth_const<Model3d>(i),
            persp
        );
    }

    for (size_t i = 0; i < point_2d_cnt; i++) {
        this->draw_point(
            scene.nth_const<CoordPair>(i)
        );
    }

    for (size_t i = 0; i < point_3d_cnt; i++) {
        this->draw_point(
            scene.nth_const<CoordTriple>(i),
            persp
        );
    }
}

} // end of namespace djf_3d
