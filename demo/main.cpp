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
*/

#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include "../src/Canvas.hpp"
#include "../src/Line2D.hpp"

int main(void) {
    /* Here we use std::unique_ptr to create objects that will be
       deallocated for us when they go out of scope. */
    std::unique_ptr<Canvas> canvas(
        new Canvas(
            "Dante's C++ Project",
            600,
            600
        )
    );

    std::unique_ptr<Line2D> line(
        new Line2D(
            200.0,
            200.0,
            300.0,
            300.0
        )
    );

    /* The method exit() returns true if the user clicks the close
       button or presses the X key; otherwise it returns false. */
    while (!canvas->exit()) {
        /* Thanks to this nice, clean, object-oriented API I've written,
           we don't need to concern ourselves with the hairy SDL2
           functions implemented in pure C under the hood. This makes
           the code much less verbose and encapsulates all the raw
           memory management while leaving us with control over what
           actually matters to us. */
        canvas->set_draw_color(0, 0, 0);
        canvas->fill_window();
        canvas->set_draw_color(0, 255, 50);
        canvas->draw_line(
            (int) line->get_endpoint_0_x(),
            (int) line->get_endpoint_0_y(),
            (int) line->get_endpoint_1_x(),
            (int) line->get_endpoint_1_y()
        );

        line->rotate_endpoint_0(
            line->get_endpoint_1_x(),
            line->get_endpoint_1_y(),
            1.0
        );

        canvas->refresh();

        /* 60 FPS framerate */
        std::this_thread::sleep_for(
            std::chrono::microseconds(16667)
        );
    }

    return 0;
}
