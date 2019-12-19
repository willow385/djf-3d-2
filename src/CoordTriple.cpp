#include <stdexcept>
#include <cmath>
#include "CoordTriple.hpp"

CoordTriple::CoordTriple(
    float x,
    float y,
    float z
) {
    x_pos = x;
    y_pos = y;
    z_pos = z;
}

CoordTriple::~CoordTriple(void) {}

float CoordTriple::get_pos(Axis axis) const {
    switch (axis) {
        case Axis::X:
            return x_pos;
        case Axis::Y:
            return y_pos;
        case Axis::Z:
            return z_pos;
        default:
            throw std::invalid_argument(
                "Invalid axis for CoordTriple::get_pos()"
            );
    }
}

void CoordTriple::translate(Axis axis, float amount) {
    float *which_pos;
    switch (axis) {
        case Axis::X:
            which_pos = &x_pos;
            break;
        case Axis::Y:
            which_pos = &y_pos;
            break;
        case Axis::Z:
            which_pos = &z_pos;
            break;
        default:
            throw std::invalid_argument(
                "Invalid axis for CoordTriple::translate()"
            );
    }

    *which_pos += amount;
}

void CoordTriple::rotate_3d(
    Axis axis,
    const CoordTriple *axis_point,
    float theta_degrees
) {
    float *pos_0;
    float *pos_1;
    float about_0;
    float about_1;
    switch (axis) {
        case Axis::X:
            pos_0 = &z_pos;
            pos_1 = &y_pos;
            about_0 = axis_point->get_pos(Axis::Z);
            about_1 = axis_point->get_pos(Axis::Y);
            break;
        case Axis::Y:
            pos_0 = &x_pos;
            pos_1 = &z_pos;
            about_0 = axis_point->get_pos(Axis::X);
            about_1 = axis_point->get_pos(Axis::Z);
            break;
        case Axis::Z:
            pos_0 = &x_pos;
            pos_1 = &y_pos;
            about_0 = axis_point->get_pos(Axis::X);
            about_1 = axis_point->get_pos(Axis::Y);
            break;
        default:
            throw std::invalid_argument(
                "Invalid axis for CoordTriple::rotate_3d()"
            );
    }

    float radians = theta_degrees * (3.14159 / 180.0);

    float sin_theta = std::sin(radians);
    float cos_theta = std::cos(radians);

    *pos_0 -= about_0;
    *pos_1 -= about_1;

    float new_0 = *pos_0 * cos_theta - *pos_1 * sin_theta;
    float new_1 = *pos_0 * sin_theta + *pos_1 * cos_theta;

    *pos_0 = new_0 + about_0;
    *pos_1 = new_1 + about_1;
}

float CoordTriple::project_2d_x(
    float vanish_x,
    float fov
) const {
    /* The apparent x-position is going to be a weighted average
       between the actual x-position and the x-position of the
       vanishing point, weighted by the y-position. */
    float average = (
        x_pos + (
            (y_pos / fov) * vanish_x
        )
    ) / (
        1 + (y_pos / fov)
    );

    return average;
}

float CoordTriple::project_2d_y(
    float vanish_y,
    float fov
) const {
    float average = (
        z_pos + (
            (y_pos / fov) * vanish_y
        )
    ) / (
        1 + (y_pos / fov)
    );

    return average;
}
