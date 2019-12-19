#include "CoordPair.hpp"
#include <cmath>

CoordPair::CoordPair(float x, float y) {
    x_pos = x;
    y_pos = y;
}

CoordPair::~CoordPair(void) {}

float CoordPair::get_x_pos(void) const {
    return x_pos;
}

float CoordPair::get_y_pos(void) const {
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
    float radians = theta_degrees * (3.14159 / 180.0);

    float sin_theta = std::sin(radians);
    float cos_theta = std::cos(radians);

    x_pos -= axis_x;
    y_pos -= axis_y;

    float xnew = x_pos * cos_theta - y_pos * sin_theta;
    float ynew = x_pos * sin_theta + y_pos * cos_theta;

    x_pos = xnew + axis_x;
    y_pos = ynew + axis_y;
}
