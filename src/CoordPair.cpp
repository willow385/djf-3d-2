#include "CoordPair.hpp"

#ifndef CMATH
#define CMATH
#include <cmath>
#endif

namespace djf_3d {

CoordPair::CoordPair(const float x, const float y) {
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

void CoordPair::translate_x_pos(const float amount) {
    x_pos += amount;
}

void CoordPair::translate_y_pos(const float amount) {
    y_pos += amount;
}

void CoordPair::rotate_around(
    const float axis_x,
    const float axis_y,
    const float theta_degrees
) {
    const float radians = theta_degrees * (3.14159 / 180.0);

    const float sin_theta = std::sin(radians);
    const float cos_theta = std::cos(radians);

    x_pos -= axis_x;
    y_pos -= axis_y;

    const float xnew = x_pos * cos_theta - y_pos * sin_theta;
    const float ynew = x_pos * sin_theta + y_pos * cos_theta;

    x_pos = xnew + axis_x;
    y_pos = ynew + axis_y;
}

} // end of namespace djf_3d
