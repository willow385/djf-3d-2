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
#include <stdexcept>
#include <memory>
#include <thread>
#include <chrono>
#include "../src/Canvas.hpp"
#include "../src/CoordTriple.hpp"

/* This Trianlge class is just for demo purposes. Later I
   intend to write functionality for displaying arbitrary
   geometric shapes loaded from external files. */
class Triangle {
public:
    CoordTriple *vertex_0;
    CoordTriple *vertex_1;
    CoordTriple *vertex_2;

    Triangle(
        float v_0_x,
        float v_0_y,
        float v_0_z,
        float v_1_x,
        float v_1_y,
        float v_1_z,
        float v_2_x,
        float v_2_y,
        float v_2_z
    ) {
        vertex_0 = new CoordTriple(v_0_x, v_0_y, v_0_z);
        vertex_1 = new CoordTriple(v_1_x, v_1_y, v_1_z);
        vertex_2 = new CoordTriple(v_2_x, v_2_y, v_2_z);
    }

    ~Triangle(void) {
        delete vertex_0;
        delete vertex_1;
        delete vertex_2;
    }
};

int game_loop(std::unique_ptr<Canvas> canvas) {
    std::unique_ptr<Triangle> triangle(
        new Triangle(
            300, 0, 300,
            200, 0, 500,
            400, 0, 500
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
            (int) triangle->vertex_0->project_2d_x(300, 1000),
            (int) triangle->vertex_0->project_2d_y(300, 1000),
            (int) triangle->vertex_1->project_2d_x(300, 1000),
            (int) triangle->vertex_1->project_2d_y(300, 1000)
        );
        canvas->draw_line(
            (int) triangle->vertex_1->project_2d_x(300, 1000),
            (int) triangle->vertex_1->project_2d_y(300, 1000),
            (int) triangle->vertex_2->project_2d_x(300, 1000),
            (int) triangle->vertex_2->project_2d_y(300, 1000)
        );
        canvas->draw_line(
            (int) triangle->vertex_2->project_2d_x(300, 1000),
            (int) triangle->vertex_2->project_2d_y(300, 1000),
            (int) triangle->vertex_0->project_2d_x(300, 1000),
            (int) triangle->vertex_0->project_2d_y(300, 1000)
        );

        canvas->refresh();

        triangle->vertex_1->rotate_3d(
            Axis::Z,
            triangle->vertex_0,
            1
        );

        triangle->vertex_2->rotate_3d(
            Axis::Z,
            triangle->vertex_0,
            1
        );

        /* 60 FPS framerate */
        std::this_thread::sleep_for(
            std::chrono::microseconds(16667)
        );
    }

    return 0;
}

int main(void) {
    try {
        std::unique_ptr<Canvas> canvas(
            new Canvas(
                "Rotating 3D triangle written in modern C++",
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
