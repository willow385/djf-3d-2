#include "CoordPair.hpp"
#include <cmath>

CoordPair::CoordPair(float x, float y) {
    x_pos = x;
    y_pos = y;
}

float CoordPair::get_x_pos(void) {
    return x_pos;
}

float CoordPair::get_y_pos(void) {
    return y_pos;
}

void CoordPair::translate_x_pos(float amount) {
    x_pos += amount;
}

void CoordPair::translate_y_pos(float amount) {
    y_pos += amount;
}

void CoordPair::rotate_around(
    float axis_x,
    float axis_y,
    float theta_degrees
) {
    const float degree_radian_ratio = 0.0174533;

    float radians = theta_degrees * degree_radian_ratio;

    float s = std::sin(radians);
    float c = std::cos(radians);

    float translated_x = x_pos - axis_x;
    float translated_y = y_pos - axis_y;

    float x_new = translated_x * c - translated_y * s;
    float y_new = translated_y * s + translated_y * c;

    x_pos = x_new;
    y_pos = y_new;
}
