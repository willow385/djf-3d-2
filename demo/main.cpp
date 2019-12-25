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

    If you run "make run" the makefile will use the program to load
    demo/chair1.obj. You can also load other .obj files with this program,
    but there's no guarantee that they'll look right, because this will
    just draw a line from each vertex to the next one, then one from the
    last vertex to the zeroth one.
*/

#include <iostream>
#include <string>
#include <stdexcept>
#include <memory>
#include <thread>
#include <chrono>
#include "../src/djf_3d.h"

int game_loop(
    std::unique_ptr<djf_3d::Canvas> canvas,
    std::unique_ptr<djf_3d::Model3d> model
) {

    /* This will contain information concerning the 2d surface onto which
       we want to project our 3d points. */
    djf_3d::Perspective perspective_context(
        (int) (canvas->get_width()  / 2), /* vanishing point x-coord */
        (int) (canvas->get_height() / 2), /* vanishing point y-coord */
        1200.0 /* how strongly objects appear to converge to horizon */
    );

    /* This will be used to store the state of the keyboard. */
    djf_3d::KeyboardState keyboard_state;

    /* The method exit() returns true if the user clicks the close
       button or presses the X key; otherwise it returns false. */
    while (!canvas->exit()) {
        /* Set the color to black. */
        canvas->set_draw_color(0, 0, 0);

        /* Fill the window. */
        canvas->fill_window();

        /* Set the color to green. */
        canvas->set_draw_color(0, 255, 50);

        /* Draw the model. */
        canvas->draw_model3d(*model, perspective_context);

        /* Refresh the frame so we can see what we just drew. */
        canvas->refresh();

        /* Get the present keyboard state. */
        keyboard_state = canvas->get_keyboard_state();

        /* Move the model based on user input. */
        if (keyboard_state.A) {
            model->rotate_self(
                djf_3d::Axis::Z,
                -1.0
            );
        }
        if (keyboard_state.D) {
            model->rotate_self(
                djf_3d::Axis::Z,
                +1.0
            );
        }
        if (keyboard_state.W) {
            model->rotate_self(
                djf_3d::Axis::X,
                -1.0
            );
        }
        if (keyboard_state.S) {
            model->rotate_self(
                djf_3d::Axis::X,
                +1.0
            );
        }
        if (keyboard_state.Q) {
            model->rotate_self(
                djf_3d::Axis::Y,
                -1.0
            );
        }
        if (keyboard_state.E) {
            model->rotate_self(
                djf_3d::Axis::Y,
                +1.0
            );
        }
        if (keyboard_state.I) {
            model->translate(
                djf_3d::Axis::Y,
                -5.0
            );
        }
        if (keyboard_state.O) {
            model->translate(
                djf_3d::Axis::Y,
                +5.0
            );
        }
        if (keyboard_state.left_arr) {
            model->translate(
                djf_3d::Axis::X,
                -2.0
            );
        }
        if (keyboard_state.right_arr) {
            model->translate(
                djf_3d::Axis::X,
                +2.0
            );
        }
        if (keyboard_state.up_arr) {
            model->translate(
                djf_3d::Axis::Z,
                -2.0
            );
        }
        if (keyboard_state.down_arr) {
            model->translate(
                djf_3d::Axis::Z,
                +2.0
            );
        }
        if (keyboard_state.X) { break; }

        /* Delay refreshing for a 60 FPS framerate. */
        std::this_thread::sleep_for(
            std::chrono::microseconds(16667)
        );
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr
            << argv[0]
            << ": error: no file passed!"
            << std::endl;
        std::cerr
            << "usage: "
            << argv[0]
            << " [.obj file]"
            << std::endl;
        return 1;
    }

    try {
        std::unique_ptr<djf_3d::Canvas> canvas(
            new djf_3d::Canvas(
                "Controls: W/A/S/D/Q/E to rotate, I/O to zoom, arrow keys to pan",
                600,
                600
            )
        );

        std::unique_ptr<djf_3d::Model3d> model(
            new djf_3d::Model3d(argv[1])
        );

        int return_val = game_loop(
            std::move(canvas),
            std::move(model)
        );

        std::cout << "Game exited normally." << std::endl;
        return return_val;
    } catch (std::exception& e) {
        std::cerr << "Aborting the program." << std::endl;
        return 1;
    }
}
