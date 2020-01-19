#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <string>
#include <SDL.h>
#include "Vec2f.h"
#include "Vec3f.h"
#include "Perspective.h"
#include "KeyboardState.h"
#include "Model3d.h"
#include "Color.h"
#include "Scene.h"
#include "Polygon.h"
#include "Canvas.h"

namespace djf_3d {

Canvas::Canvas(
    const std::string& title,
    const int width,
    const int height,
    const int viewer_y_pos
) {
    std::cout <<
        "Calling ctor djf_3d::Canvas::Canvas()... ";

    SDL_Init(SDL_INIT_VIDEO);

    width_px = width;
    height_px = height;
    viewer_y_position = viewer_y_pos;

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
    event = static_cast<SDL_Event *>(
        std::malloc(sizeof(SDL_Event))
    );

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

int Canvas::get_viewer_y_pos(void) const noexcept {
    return viewer_y_position;
}

bool Canvas::exit(void) noexcept {
    SDL_PollEvent(event);
    return (event->type == SDL_QUIT);
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
    result.escape    = static_cast<bool>(state[SDL_SCANCODE_ESCAPE]);
    result.backtick  = static_cast<bool>(state[SDL_SCANCODE_GRAVE]);
    result.dig_1     = static_cast<bool>(state[SDL_SCANCODE_1]);
    result.dig_2     = static_cast<bool>(state[SDL_SCANCODE_2]);
    result.dig_3     = static_cast<bool>(state[SDL_SCANCODE_3]);
    result.dig_4     = static_cast<bool>(state[SDL_SCANCODE_4]);
    result.dig_5     = static_cast<bool>(state[SDL_SCANCODE_5]);
    result.dig_6     = static_cast<bool>(state[SDL_SCANCODE_6]);
    result.dig_7     = static_cast<bool>(state[SDL_SCANCODE_7]);
    result.dig_8     = static_cast<bool>(state[SDL_SCANCODE_8]);
    result.dig_9     = static_cast<bool>(state[SDL_SCANCODE_9]);
    result.dig_0     = static_cast<bool>(state[SDL_SCANCODE_0]);
    result.hyphen    = static_cast<bool>(state[SDL_SCANCODE_MINUS]);
    result.equals    = static_cast<bool>(state[SDL_SCANCODE_EQUALS]);
    result.backspace = static_cast<bool>(state[SDL_SCANCODE_BACKSPACE]);
    result.tab       = static_cast<bool>(state[SDL_SCANCODE_TAB]);
    result.Q         = static_cast<bool>(state[SDL_SCANCODE_Q]);
    result.W         = static_cast<bool>(state[SDL_SCANCODE_W]);
    result.E         = static_cast<bool>(state[SDL_SCANCODE_E]);
    result.R         = static_cast<bool>(state[SDL_SCANCODE_R]);
    result.T         = static_cast<bool>(state[SDL_SCANCODE_T]);
    result.Y         = static_cast<bool>(state[SDL_SCANCODE_Y]);
    result.U         = static_cast<bool>(state[SDL_SCANCODE_U]);
    result.I         = static_cast<bool>(state[SDL_SCANCODE_I]);
    result.O         = static_cast<bool>(state[SDL_SCANCODE_O]);
    result.P         = static_cast<bool>(state[SDL_SCANCODE_P]);
    result.open_bracket
        = static_cast<bool>(state[SDL_SCANCODE_LEFTBRACKET]);
    result.close_bracket
        = static_cast<bool>(state[SDL_SCANCODE_RIGHTBRACKET]);
    result.back_slash
        = static_cast<bool>(state[SDL_SCANCODE_BACKSLASH]);
    result.A         = static_cast<bool>(state[SDL_SCANCODE_A]);
    result.S         = static_cast<bool>(state[SDL_SCANCODE_S]);
    result.D         = static_cast<bool>(state[SDL_SCANCODE_D]);
    result.F         = static_cast<bool>(state[SDL_SCANCODE_F]);
    result.G         = static_cast<bool>(state[SDL_SCANCODE_G]);
    result.H         = static_cast<bool>(state[SDL_SCANCODE_H]);
    result.J         = static_cast<bool>(state[SDL_SCANCODE_J]);
    result.K         = static_cast<bool>(state[SDL_SCANCODE_K]);
    result.L         = static_cast<bool>(state[SDL_SCANCODE_L]);
    result.semicolon
        = static_cast<bool>(state[SDL_SCANCODE_SEMICOLON]);
    result.quote
        = static_cast<bool>(state[SDL_SCANCODE_APOSTROPHE]);
    result.enter     = static_cast<bool>(state[SDL_SCANCODE_RETURN]);
    result.shift     = static_cast<bool>(
        state[SDL_SCANCODE_RSHIFT]
    ||
        state[SDL_SCANCODE_LSHIFT]
    );
    result.Z         = static_cast<bool>(state[SDL_SCANCODE_Z]);
    result.X         = static_cast<bool>(state[SDL_SCANCODE_X]);
    result.C         = static_cast<bool>(state[SDL_SCANCODE_C]);
    result.V         = static_cast<bool>(state[SDL_SCANCODE_V]);
    result.B         = static_cast<bool>(state[SDL_SCANCODE_B]);
    result.N         = static_cast<bool>(state[SDL_SCANCODE_N]);
    result.M         = static_cast<bool>(state[SDL_SCANCODE_M]);
    result.comma     = static_cast<bool>(state[SDL_SCANCODE_COMMA]);
    result.period    = static_cast<bool>(state[SDL_SCANCODE_PERIOD]);
    result.forward_slash
        = static_cast<bool>(state[SDL_SCANCODE_SLASH]);
    result.ctrl      = static_cast<bool>(
        state[SDL_SCANCODE_RCTRL]
    ||
        state[SDL_SCANCODE_LCTRL]
    );
    result.home      = static_cast<bool>(state[SDL_SCANCODE_HOME]);
    result.alt       = static_cast<bool>(
        state[SDL_SCANCODE_RALT]
    ||
        state[SDL_SCANCODE_LALT]
    );
    result.left_arr  = static_cast<bool>(state[SDL_SCANCODE_LEFT]);
    result.up_arr    = static_cast<bool>(state[SDL_SCANCODE_UP]);
    result.down_arr  = static_cast<bool>(state[SDL_SCANCODE_DOWN]);
    result.right_arr = static_cast<bool>(state[SDL_SCANCODE_RIGHT]);
    result.space     = static_cast<bool>(state[SDL_SCANCODE_SPACE]);

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
        static_cast<Uint8>(r),
        static_cast<Uint8>(g),
        static_cast<Uint8>(b),
        static_cast<Uint8>(alpha)
    );
}

void Canvas::set_draw_color(const Color& color) noexcept {
    SDL_SetRenderDrawColor(
        renderer,
        static_cast<Uint8>(color.red),
        static_cast<Uint8>(color.green),
        static_cast<Uint8>(color.blue),
        static_cast<Uint8>(color.alpha)
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
    const Vec2f& point
) noexcept {
    SDL_RenderDrawPoint(
        renderer,
        static_cast<int>(point.get_x_pos()),
        static_cast<int>(point.get_y_pos())
    );
}

void Canvas::draw_point(
    const Vec3f& point,
    const Vec2f& vanish_point,
    const float fov
) noexcept {
    if (point.get_pos<Axis::Y>() < viewer_y_position) return;

    SDL_RenderDrawPoint(
        renderer,
        static_cast<int>(point.project_2d_x(
            static_cast<int>(vanish_point.get_x_pos()),
            fov
        )),
        static_cast<int>(point.project_2d_y(
            static_cast<int>(vanish_point.get_y_pos()),
            fov
        ))
    );
}

void Canvas::draw_point(
    const Vec3f& point,
    const Perspective& perspective
) noexcept {
    if (point.get_pos<Axis::Y>() < viewer_y_position) return;

    Vec2f projection_2d
        = point.project_2d(perspective);
    SDL_RenderDrawPoint(
        renderer,
        static_cast<int>(projection_2d.get_x_pos()),
        static_cast<int>(projection_2d.get_y_pos())
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
    const Vec2f& point_0,
    const Vec2f& point_1
) noexcept {
    SDL_RenderDrawLine(
        renderer,
        static_cast<int>(point_0.get_x_pos()),
        static_cast<int>(point_0.get_y_pos()),
        static_cast<int>(point_1.get_x_pos()),
        static_cast<int>(point_1.get_y_pos())
    );
}

void Canvas::draw_line(
    const Vec3f& point_0,
    const Vec3f& point_1,
    const Perspective& perspective
) noexcept {
    if (
        point_0.get_pos<Axis::Y>() < viewer_y_position
    ||
        point_1.get_pos<Axis::Y>() < viewer_y_position
    ) return;

    Vec2f point_0_2d
        = point_0.project_2d(perspective);
    Vec2f point_1_2d
        = point_1.project_2d(perspective);
    SDL_RenderDrawLine(
        renderer,
        static_cast<int>(point_0_2d.get_x_pos()),
        static_cast<int>(point_0_2d.get_y_pos()),
        static_cast<int>(point_1_2d.get_x_pos()),
        static_cast<int>(point_1_2d.get_y_pos())
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
    int num_faces = model.face_cnt();
    for (int i = 0; i < num_verts; i++) {
        this->draw_point(
            model.nth_vertex(i),
            persp
        );
    }

    for (int i = 0; i < num_faces; i++) {
        this->draw_poly(
            model.nth_face(i),
            persp
        );
    }
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
            scene.nth<Model3d>(i),
            persp
        );
    }

    for (size_t i = 0; i < point_2d_cnt; i++) {
        this->draw_point(
            scene.nth<Vec2f>(i)
        );
    }

    for (size_t i = 0; i < point_3d_cnt; i++) {
        this->draw_point(
            scene.nth<Vec3f>(i),
            persp
        );
    }
}

void Canvas::draw_poly(
    const Polygon& poly,
    const Perspective& persp
) noexcept {
    size_t vert_cnt = poly.vertices.size();
    if (vert_cnt == 0) return;

    if (vert_cnt == 1) {
        this->draw_point(
            *poly.vertices[0],
            persp
        );
        return;
    }

    if (vert_cnt == 2) {
        this->draw_line(
            *poly.vertices[0],
            *poly.vertices[1],
            persp
        );
        return;
    }

    for (size_t i = 0; i < vert_cnt - 1; i++) {
        this->draw_line(
            *poly.vertices[i],
            *poly.vertices[i+1],
            persp
        );
    }

    this->draw_line(
        *poly.vertices[vert_cnt - 1],
        *poly.vertices[0],
        persp
    );
}

} // end of namespace djf_3d
