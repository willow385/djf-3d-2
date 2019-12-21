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

/* This Pyramid class is just for demo purposes. Later I
   intend to write functionality for displaying arbitrary
   geometric shapes loaded from external files. */
class Pyramid {
public:
    djf_3d::CoordTriple *vertex_0;
    djf_3d::CoordTriple *vertex_1;
    djf_3d::CoordTriple *vertex_2;
    djf_3d::CoordTriple *vertex_3;

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
    ) {
        vertex_0 = new djf_3d::CoordTriple(v_0_x, v_0_y, v_0_z);
        vertex_1 = new djf_3d::CoordTriple(v_1_x, v_1_y, v_1_z);
        vertex_2 = new djf_3d::CoordTriple(v_2_x, v_2_y, v_2_z);
        vertex_3 = new djf_3d::CoordTriple(v_3_x, v_3_y, v_3_z);
    }

    ~Pyramid(void) {
        delete vertex_0;
        delete vertex_1;
        delete vertex_2;
        delete vertex_3;
    }
};

int game_loop(std::unique_ptr<djf_3d::Canvas> canvas) {
    std::unique_ptr<Pyramid> pyramid(
        /* I used a calculator to work out what the coordinates should
           be to roughly approximate a regular tetrahedron of side
           length 300. */
        new Pyramid(
            300, 0, 200,
            150, 129.9038, 425,
            450, 129.9038, 425,
            300, -198.4313, 425
        )
    );

    const float vanish_location = 300.0;
    const float fov = 1200.0;

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
            (int) pyramid->vertex_0->project_2d_x(vanish_location, fov),
            (int) pyramid->vertex_0->project_2d_y(vanish_location, fov),
            (int) pyramid->vertex_1->project_2d_x(vanish_location, fov),
            (int) pyramid->vertex_1->project_2d_y(vanish_location, fov)
        );
        canvas->draw_line(
            (int) pyramid->vertex_1->project_2d_x(vanish_location, fov),
            (int) pyramid->vertex_1->project_2d_y(vanish_location, fov),
            (int) pyramid->vertex_2->project_2d_x(vanish_location, fov),
            (int) pyramid->vertex_2->project_2d_y(vanish_location, fov)
        );
        canvas->draw_line(
            (int) pyramid->vertex_2->project_2d_x(vanish_location, fov),
            (int) pyramid->vertex_2->project_2d_y(vanish_location, fov),
            (int) pyramid->vertex_0->project_2d_x(vanish_location, fov),
            (int) pyramid->vertex_0->project_2d_y(vanish_location, fov)
        );
        canvas->draw_line(
            (int) pyramid->vertex_0->project_2d_x(vanish_location, fov),
            (int) pyramid->vertex_0->project_2d_y(vanish_location, fov),
            (int) pyramid->vertex_3->project_2d_x(vanish_location, fov),
            (int) pyramid->vertex_3->project_2d_y(vanish_location, fov)
        );
        canvas->draw_line(
            (int) pyramid->vertex_1->project_2d_x(vanish_location, fov),
            (int) pyramid->vertex_1->project_2d_y(vanish_location, fov),
            (int) pyramid->vertex_3->project_2d_x(vanish_location, fov),
            (int) pyramid->vertex_3->project_2d_y(vanish_location, fov)
        );
        canvas->draw_line(
            (int) pyramid->vertex_2->project_2d_x(vanish_location, fov),
            (int) pyramid->vertex_2->project_2d_y(vanish_location, fov),
            (int) pyramid->vertex_3->project_2d_x(vanish_location, fov),
            (int) pyramid->vertex_3->project_2d_y(vanish_location, fov)
        );


        canvas->refresh();

        pyramid->vertex_1->rotate_3d(
            djf_3d::Axis::Z,
            pyramid->vertex_0,
            1
        );
        pyramid->vertex_2->rotate_3d(
            djf_3d::Axis::Z,
            pyramid->vertex_0,
            1
        );
        pyramid->vertex_3->rotate_3d(
            djf_3d::Axis::Z,
            pyramid->vertex_0,
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
        std::unique_ptr<djf_3d::Canvas> canvas(
            new djf_3d::Canvas(
                "Rotating 3D Pyramid written in modern C++",
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
