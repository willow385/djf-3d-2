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

template <Axis axis>
float Vec3f::get_pos(void) const noexcept {
    return components[static_cast<int>(axis)];
}

template float Vec3f::get_pos<Axis::X>(void) const noexcept;
template float Vec3f::get_pos<Axis::Y>(void) const noexcept;
template float Vec3f::get_pos<Axis::Z>(void) const noexcept;

template <Axis axis>
void Vec3f::translate(const float distance) noexcept {
    components[static_cast<int>(axis)] += distance;
}

template void Vec3f::translate<Axis::X>(
    const float distance
) noexcept;
template void Vec3f::translate<Axis::Y>(
    const float distance
) noexcept;
template void Vec3f::translate<Axis::Z>(
    const float distance
) noexcept;

template <>
void Vec3f::rotate_3d<Axis::X>(
    const Vec3f& axis_point,
    const float theta_degrees
) noexcept {
    float *pos_0 = components + 2;
    float *pos_1 = components + 1;
    float about_0 = axis_point.get_pos<Axis::Z>();
    float about_1 = axis_point.get_pos<Axis::Y>();

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

template <>
void Vec3f::rotate_3d<Axis::Y>(
    const Vec3f& axis_point,
    const float theta_degrees
) noexcept {
    float *pos_0 = components;
    float *pos_1 = components + 2;
    float about_0 = axis_point.get_pos<Axis::X>();
    float about_1 = axis_point.get_pos<Axis::Z>();

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

template <>
void Vec3f::rotate_3d<Axis::Z>(
    const Vec3f& axis_point,
    const float theta_degrees
) noexcept {
    float *pos_0 = components;
    float *pos_1 = components + 1;
    float about_0 = axis_point.get_pos<Axis::X>();
    float about_1 = axis_point.get_pos<Axis::Y>();

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

/* Instead of matrix multiplication, we just use a weighted
   average to project things onto the surface. */

float Vec3f::project_2d_x(
    const float vanish_x,
    const float fov
) const noexcept {
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