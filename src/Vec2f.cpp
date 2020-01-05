#include <cmath>
#include "Vec2f.h"

namespace djf_3d {

Vec2f::Vec2f(
    const float x,
    const float y
) noexcept {
    x_pos = x;
    y_pos = y;
}

Vec2f::~Vec2f(void) noexcept {}

float Vec2f::get_x_pos(void) const noexcept {
    return x_pos;
}

float Vec2f::get_y_pos(void) const noexcept {
    return y_pos;
}

void Vec2f::translate_x_pos(
    const float amount
) noexcept {
    x_pos += amount;
}

void Vec2f::translate_y_pos(
    const float amount
) noexcept {
    y_pos += amount;
}

void Vec2f::rotate_around(
    const float axis_x,
    const float axis_y,
    const float theta_degrees
) noexcept {
    const float radians
        = theta_degrees * (3.14159 / 180.0);

    const float sin_theta = std::sin(radians);
    const float cos_theta = std::cos(radians);

    x_pos -= axis_x;
    y_pos -= axis_y;

    const float xnew
        = x_pos * cos_theta - y_pos * sin_theta;
    const float ynew
        = x_pos * sin_theta + y_pos * cos_theta;

    x_pos = xnew + axis_x;
    y_pos = ynew + axis_y;
}

void Vec2f::rotate_around(
    const Vec2f& axis,
    const float theta_degrees
) noexcept {
    const float radians
        = theta_degrees * (3.14159 / 180.0);

    const float sin_theta = std::sin(radians);
    const float cos_theta = std::cos(radians);

    x_pos -= axis.get_x_pos();
    y_pos -= axis.get_y_pos();

    const float xnew
        = x_pos * cos_theta - y_pos * sin_theta;
    const float ynew
        = x_pos * sin_theta + y_pos * cos_theta;

    x_pos = xnew + axis.get_x_pos();
    y_pos = ynew + axis.get_y_pos();
}

} // end of namespace djf_3d