/*          main.cpp file of djf-3d-2
    Copyright (C) 2019  Dante Falzone

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

    //==================================================================//

    This program is a demonstration of djf-3d-2, an object-oriented 3d
    engine written in modern C++ by Dante Falzone.

    Please note that the Pyramid class defined in this file is for
    DEMONSTRATION PURPOSES ONLY and that djf-3d-2 is STILL UNDER
    CONSTRUCTION.

    I'm pretty happy with the interfaces for wrapping SDL2 and for
    doing 3d geometry and projection, but I would like to be able to
    load arbitrary 3d models from an external file and render them.
    Soon I will probably write a Model3D class whose constructor takes
    a handle to a .obj file, or something similar.

    The Pyramid class is in my opinion the least well-written thing in
    this entire git repo, but that's okay because it's a temporary thing
    and only for this demo program; what this should really show off is
    that a) this library works and b) it provides a pretty clean and
    readable interface to the SDL C functions and hairy mathematic
    stuff under the hood.
*/

#include <iostream>
#include <stdexcept>
#include <memory>
#include <thread>
#include <chrono>
#include "../src/djf_3d.hpp"

class Pyramid {
public:
    djf_3d::CoordTriple *vertex_0;
    djf_3d::CoordTriple *vertex_1;
    djf_3d::CoordTriple *vertex_2;
    djf_3d::CoordTriple *vertex_3;
    djf_3d::CoordTriple *centroid;

    Pyramid(
        float v_0_x,
        float v_0_y,
        float v_0_z,
        float v_1_x,
        float v_1_y,
        float v_1_z,
        float v_2_x,
        float v_2_y,
        float v_2_z,
        float v_3_x,
        float v_3_y,
        float v_3_z
    ) noexcept {
        vertex_0 = new djf_3d::CoordTriple(v_0_x, v_0_y, v_0_z);
        vertex_1 = new djf_3d::CoordTriple(v_1_x, v_1_y, v_1_z);
        vertex_2 = new djf_3d::CoordTriple(v_2_x, v_2_y, v_2_z);
        vertex_3 = new djf_3d::CoordTriple(v_3_x, v_3_y, v_3_z);
        float centroid_x =
            (v_0_x + v_1_x + v_2_x + v_3_x) / 4;
        float centroid_y =
            (v_0_y + v_1_y + v_2_y + v_3_y) / 4;
        float centroid_z =
            (v_0_z + v_1_z + v_2_z + v_3_z) / 4;
        centroid = new djf_3d::CoordTriple(
            centroid_x,
            centroid_y,
            centroid_z
        );
    }

    ~Pyramid(void) noexcept {
        delete vertex_0;
        delete vertex_1;
        delete vertex_2;
        delete vertex_3;
        delete centroid;
    }

    void rotate(const djf_3d::Axis axis, float degrees) {
        vertex_0->rotate_3d(
            axis,
            *centroid,
            degrees
        );
        vertex_1->rotate_3d(
            axis,
            *centroid,
            degrees
        );
        vertex_2->rotate_3d(
            axis,
            *centroid,
            degrees
        );
        vertex_3->rotate_3d(
            axis,
            *centroid,
            degrees
        );
    }
};

int game_loop(std::unique_ptr<djf_3d::Canvas> canvas) {

    std::unique_ptr<Pyramid> pyramid(
        new Pyramid(
            300, 0, 200,
            150, 100, 425,
            450, 100, 425,
            300, -150, 425
        )
    );

    /* This will contain information concerning the 2d surface onto which
       we want to project our 3d points. */
    djf_3d::Perspective perspective_context(
        300.0, /* x-coordinate of the vanishing point */
        300.0, /* y-coordinate of the vanishing point */
        1200.0 /* how strongly objects appear to converge to horizon */
    );

    /* This will be used to store the state of the keyboard. */
    djf_3d::KeyboardState keyboard_state;

    /* The method exit() returns true if the user clicks the close
       button or presses the X key; otherwise it returns false. */
    while (!canvas->exit()) {
        /* Set the color to black */
        canvas->set_draw_color(0, 0, 0);

        /* Fill the window */
        canvas->fill_window();

        /* Set the color to green */
        canvas->set_draw_color(0, 255, 50);

        /* Draw lines between the pyramid's vertices */
        canvas->draw_line(
            *pyramid->vertex_0,
            *pyramid->vertex_1,
            perspective_context
        );
        canvas->draw_line(
            *pyramid->vertex_0,
            *pyramid->vertex_2,
            perspective_context
        );
        canvas->draw_line(
            *pyramid->vertex_0,
            *pyramid->vertex_3,
            perspective_context
        );
        canvas->draw_line(
            *pyramid->vertex_1,
            *pyramid->vertex_2,
            perspective_context
        );
        canvas->draw_line(
            *pyramid->vertex_2,
            *pyramid->vertex_3,
            perspective_context
        );
        canvas->draw_line(
            *pyramid->vertex_3,
            *pyramid->vertex_1,
            perspective_context
        );

        /* Refresh the frame so we can see what we just drew */
        canvas->refresh();

        /* Get the present keyboard state */
        keyboard_state = canvas->get_keyboard_state();

        /* Handle WASD key input and rotate the pyramid */
        if (keyboard_state.W) {
            pyramid->rotate(
                djf_3d::Axis::X,
                -1
            );
        }

        if (keyboard_state.S) {
            pyramid->rotate(
                djf_3d::Axis::X,
                1
            );
        }

        if (keyboard_state.A) {
            pyramid->rotate(
                djf_3d::Axis::Z,
                -1
            );
        }

        if (keyboard_state.D) {
            pyramid->rotate(
                djf_3d::Axis::Z,
                1
            );
        }

        if (keyboard_state.Q) {
            pyramid->rotate(
                djf_3d::Axis::Y,
                -1
            );
        }

        if (keyboard_state.E) {
            pyramid->rotate(
                djf_3d::Axis::Y,
                1
            );
        }

        /* Delay refreshing for a 60 FPS framerate */
        std::this_thread::sleep_for(
            std::chrono::microseconds(16667)
        );
    }

    return 0;
}

int main(void) {
    try {
        /* nice & fancy modern C++1x features */
        std::unique_ptr<djf_3d::Canvas> canvas(
            new djf_3d::Canvas(
                "Use W, A, S, D, Q, E keys to rotate pyramid",
                600,
                600
            )
        );
        int return_val = game_loop(std::move(canvas));
        std::cout << "Game exited normally." << std::endl;
        return return_val;
    } catch (std::exception& e) {
        std::cerr << "Aborting the program." << std::endl;
        return 1;
    }
}
