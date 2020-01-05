/*          main.cpp file of djf-3d-2
    Copyright (C) 2019  Dante Falzone

    djf-3d-2 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    djf-3d-2 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

    //==================================================================//

    This program is a demonstration of djf-3d-2, an object-oriented 3d
    engine written in modern C++ by Dante Falzone.

    If you run "make run-demo" the makefile will use the program to load
    demo/utah_teapot.obj You can also load other .obj files with this program,
    but it doesn't always correctly parse the face info.
*/

#include <iostream>
#include <string>
#include <djf-3d-2/djf-3d.h>

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

    // First we create a Canvas to draw things on.
    std::string title(
        "Controls: W/A/S/D/Q/E to rotate, I/O to zoom, arrow keys to pan"
    );
    djf_3d::Canvas canvas(
        title,
        600,
        600
    );

    // Next we create a Model.
    djf_3d::Model3d model(argv[1]);

    /* We create a Perspective containing information
       needed to project 3d objects on a 2d surface,
       namely the location of the vanishing point and
       the FOV. */
    djf_3d::Perspective perspective_context(
        (int) (canvas.get_width()  / 2), // vp x-coord
        (int) (canvas.get_height() / 2), // vp y-coord
        1200.0 // how strongly objects converge to horizon
    );

    // This object will store info about the keyboard.
    djf_3d::KeyboardState keyboard_state;

    // Here we create a palette of pretty Colors to use.
    djf_3d::Color black = {0, 0, 0, 0};
    djf_3d::Color green = {0, 255, 50, 0};

    /* Let's print a helpful terminal message for the
       user's sake. */
    std::cout
        << "Click the close button or press the X key to e"
        << "xit the program." << std::endl;

    /* The exit() method will return true if, when it is
       called, the user clicks the "close" button. */
    while (!canvas.exit()) {
        canvas.set_draw_color(black);
        canvas.fill_window();
        canvas.set_draw_color(green);
        canvas.draw_model3d(model, perspective_context);
        canvas.refresh();
        keyboard_state = canvas.get_keyboard_state();

        /* We move around the model(s) in the scene based
           on user input. */
        if (keyboard_state.A)
            model.rotate_self<djf_3d::Axis::Z>(-0.5);

        if (keyboard_state.D)
            model.rotate_self<djf_3d::Axis::Z>(+0.5);

        if (keyboard_state.W)
            model.rotate_self<djf_3d::Axis::X>(-0.5);

        if (keyboard_state.S)
            model.rotate_self<djf_3d::Axis::X>(+0.5);

        if (keyboard_state.Q)
            model.rotate_self<djf_3d::Axis::Y>(-0.5);

        if (keyboard_state.E)
            model.rotate_self<djf_3d::Axis::Y>(+0.5);

        if (keyboard_state.I) {
            model.translate<djf_3d::Axis::Y>(-5.0);
        }
        if (keyboard_state.O) {
            model.translate<djf_3d::Axis::Y>(+5.0);
        }
        if (keyboard_state.left_arr) {
            model.translate<djf_3d::Axis::X>(-2.0);
        }
        if (keyboard_state.right_arr) {
            model.translate<djf_3d::Axis::X>(+2.0);
        }
        if (keyboard_state.up_arr) {
            model.translate<djf_3d::Axis::Z>(-2.0);
        }
        if (keyboard_state.down_arr) {
            model.translate<djf_3d::Axis::Z>(+2.0);
        }

        // We exit the loop if the user presses X.
        if (keyboard_state.X) break;

    }

    std::cout << "Program exited normally." << std::endl;
    return 0;
}