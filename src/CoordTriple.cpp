#include <stdexcept>
#include <cmath>

#ifndef COORDPAIR_H
#define COORDPAIR_H
#include "CoordPair.h"
#endif

#ifndef PERSPECTIVE_H
#define PERSPECTIVE_H
#include "Perspective.h"
#endif

#include "CoordTriple.h"

namespace djf_3d {

CoordTriple::CoordTriple(
    const float x,
    const float y,
    const float z
) noexcept {
    x_pos = x;
    y_pos = y;
    z_pos = z;
}

CoordTriple::~CoordTriple(void) noexcept {}

void CoordTriple::teleport(
    const float x,
    const float y,
    const float z
) noexcept {
    x_pos = x;
    y_pos = y;
    z_pos = z;
}

float CoordTriple::get_pos(const Axis axis) const {
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

void CoordTriple::translate(
    const Axis axis,
    const float amount
) {
    switch (axis) {
        case Axis::X:
            x_pos += amount;
            break;
        case Axis::Y:
            y_pos += amount;
            break;
        case Axis::Z:
            z_pos += amount;
            break;
        default:
            throw std::invalid_argument(
                "Invalid axis for CoordTriple::translate()"
            );
    }
}

void CoordTriple::rotate_3d(
    const Axis axis,
    const CoordTriple& axis_point,
    const float theta_degrees
) {
    float *pos_0;
    float *pos_1;
    float about_0;
    float about_1;
    switch (axis) {
        case Axis::X:
            pos_0 = &z_pos;
            pos_1 = &y_pos;
            about_0 = axis_point.get_pos(Axis::Z);
            about_1 = axis_point.get_pos(Axis::Y);
            break;
        case Axis::Y:
            pos_0 = &x_pos;
            pos_1 = &z_pos;
            about_0 = axis_point.get_pos(Axis::X);
            about_1 = axis_point.get_pos(Axis::Z);
            break;
        case Axis::Z:
            pos_0 = &x_pos;
            pos_1 = &y_pos;
            about_0 = axis_point.get_pos(Axis::X);
            about_1 = axis_point.get_pos(Axis::Y);
            break;
        default:
            throw std::invalid_argument(
                "Invalid axis for CoordTriple::rotate_3d()"
            );
    }

    const float radians = theta_degrees * (3.14159 / 180.0);

    const float sin_theta = std::sin(radians);
    const float cos_theta = std::cos(radians);

    *pos_0 -= about_0;
    *pos_1 -= about_1;

    const float new_0 = *pos_0 * cos_theta - *pos_1 * sin_theta;
    const float new_1 = *pos_0 * sin_theta + *pos_1 * cos_theta;

    *pos_0 = new_0 + about_0;
    *pos_1 = new_1 + about_1;
}

float CoordTriple::project_2d_x(
    const float vanish_x,
    const float fov
) const noexcept {
    /* The apparent x-position is going to be a weighted average
       between the actual x-position and the x-position of the
       vanishing point, weighted by the y-position. */
    return (
        x_pos + (
            (y_pos / fov) * vanish_x
        )
    ) / (
        1 + (y_pos / fov)
    );
}

float CoordTriple::project_2d_x(
    const Perspective& perspective
) const noexcept {
    return (
        x_pos + (
            (
                y_pos / perspective.fov
            ) * perspective.vanishing_point.get_x_pos()
        )
    ) / (
        1 + (y_pos / perspective.fov)
    );
}

float CoordTriple::project_2d_y(
    const float vanish_y,
    const float fov
) const noexcept {
    return (
        z_pos + (
            (y_pos / fov) * vanish_y
        )
    ) / (
        1 + (y_pos / fov)
    );
}

float CoordTriple::project_2d_y(
    const Perspective& perspective
) const noexcept {
    return (
        z_pos + (
            (
                y_pos / perspective.fov
            ) * perspective.vanishing_point.get_y_pos()
        )
    ) / (
        1 + (y_pos / perspective.fov)
    );
}

CoordPair CoordTriple::project_2d(
    const Perspective& perspective
) const noexcept {
    CoordPair result(
        (
            x_pos + (
                (
                    y_pos / perspective.fov
                ) * perspective.vanishing_point.get_x_pos()
            )
        ) / (
            1 + (y_pos / perspective.fov)
        ),

        (
            z_pos + (
                (
                    y_pos / perspective.fov
                ) * perspective.vanishing_point.get_y_pos()
            )
        ) / (
            1 + (y_pos / perspective.fov)
        )
    );

    return result;
}

} // end of namespace djf_3d
