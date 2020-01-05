#include <stdexcept>
#include <cmath>
#include "Vec2f.h"
#include "Perspective.h"
#include "Vec3f.h"

namespace djf_3d {

Vec3f::Vec3f(
    const float x,
    const float y,
    const float z
) noexcept {
    components[0] = x;
    components[1] = y;
    components[2] = z;
}

Vec3f::~Vec3f(void) noexcept {}

void Vec3f::set_position(
    const float x,
    const float y,
    const float z
) noexcept {
    components[0] = x;
    components[1] = y;
    components[2] = z;
}

template <>
float Vec3f::get_pos<Axis::X>(void) const {
    return components[0];
}

template <>
float Vec3f::get_pos<Axis::Y>(void) const {
    return components[1];
}

template <>
float Vec3f::get_pos<Axis::Z>(void) const {
    return components[2];
}

template <>
void Vec3f::translate<Axis::X>(const float distance) {
    components[0] += distance;
}

template <>
void Vec3f::translate<Axis::Y>(const float distance) {
    components[1] += distance;
}

template <>
void Vec3f::translate<Axis::Z>(const float distance) {
    components[2] += distance;
}

void Vec3f::rotate_3d(
    const Axis axis,
    const Vec3f& axis_point,
    const float theta_degrees
) {
    float *pos_0;
    float *pos_1;
    float about_0;
    float about_1;
    switch (axis) {
        case Axis::X:
            pos_0 = components + 2;
            pos_1 = components + 1;
            about_0 = axis_point.get_pos<Axis::Z>();
            about_1 = axis_point.get_pos<Axis::Y>();
            break;
        case Axis::Y:
            pos_0 = components;
            pos_1 = components + 2;
            about_0 = axis_point.get_pos<Axis::X>();
            about_1 = axis_point.get_pos<Axis::Z>();
            break;
        case Axis::Z:
            pos_0 = components;
            pos_1 = components + 1;
            about_0 = axis_point.get_pos<Axis::X>();
            about_1 = axis_point.get_pos<Axis::Y>();
            break;
        default:
            throw std::invalid_argument(
                "Invalid axis for Vec3f::rotate_3d()"
            );
    }

    const float radians
        = theta_degrees * (3.14159 / 180.0);

    const float sin_theta = std::sin(radians);
    const float cos_theta = std::cos(radians);

    *pos_0 -= about_0;
    *pos_1 -= about_1;

    const float new_0
        = *pos_0 * cos_theta - *pos_1 * sin_theta;
    const float new_1
        = *pos_0 * sin_theta + *pos_1 * cos_theta;

    *pos_0 = new_0 + about_0;
    *pos_1 = new_1 + about_1;
}

float Vec3f::project_2d_x(
    const float vanish_x,
    const float fov
) const noexcept {
    /* The apparent x-position is going to be a weighted
       average between the actual x-position and the
       x-position of the vanishing point, weighted by the
       y-position. */
    return (
        components[0] + (
            (components[1] / fov) * vanish_x
        )
    ) / (
        1 + (components[1] / fov)
    );
}

float Vec3f::project_2d_x(
    const Perspective& perspective
) const noexcept {
    return (
        components[0] + (
            (
                components[1] / perspective.fov
            ) * perspective.vanishing_point.get_x_pos()
        )
    ) / (
        1 + (components[1] / perspective.fov)
    );
}

float Vec3f::project_2d_y(
    const float vanish_y,
    const float fov
) const noexcept {
    return (
        components[2] + (
            (components[1] / fov) * vanish_y
        )
    ) / (
        1 + (components[1] / fov)
    );
}

float Vec3f::project_2d_y(
    const Perspective& perspective
) const noexcept {
    return (
        components[2] + (
            (
                components[1] / perspective.fov
            ) * perspective.vanishing_point.get_y_pos()
        )
    ) / (
        1 + (components[1] / perspective.fov)
    );
}

Vec2f Vec3f::project_2d(
    const Perspective& perspective
) const noexcept {
    Vec2f result(
        (
            components[0] + (
                (
                    components[1] / perspective.fov
                ) * perspective.vanishing_point.get_x_pos()
            )
        ) / (
            1 + (components[1] / perspective.fov)
        ),

        (
            components[2] + (
                (
                    components[1] / perspective.fov
                ) * perspective.vanishing_point.get_y_pos()
            )
        ) / (
            1 + (components[1] / perspective.fov)
        )
    );

    return result;
}

} // end of namespace djf_3d