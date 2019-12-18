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
#include "../src/Canvas.hpp"

int main(void) {
    std::unique_ptr<Canvas> canvas(
        new Canvas(
            "Dante's C++ Project",
            600,
            600
        )
    );

    canvas->set_draw_color(0, 255, 50);
    while (!canvas->exit()) {
        canvas->draw_line(50, 150, 150, 50);
        canvas->refresh();
    }

    return 0;
}
