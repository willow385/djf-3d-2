#ifndef MEMORY
#define MEMORY
#include <memory>
#endif

#include "Line2D.hpp"

namespace djf_3d {

Line2D::Line2D(
    const float x0,
    const float y0,
    const float x1,
    const float y1
) {
    endpoint_0 = std::make_unique<CoordPair>(x0, y0);
    endpoint_1 = std::make_unique<CoordPair>(x1, y1);
}

Line2D::~Line2D(void) {}

float Line2D::get_endpoint_0_x(void) const {
    return endpoint_0->get_x_pos();
}

float Line2D::get_endpoint_0_y(void) const {
    return endpoint_0->get_y_pos();
}

float Line2D::get_endpoint_1_x(void) const {
    return endpoint_1->get_x_pos();
}

float Line2D::get_endpoint_1_y(void) const {
    return endpoint_1->get_y_pos();
}

void Line2D::rotate_endpoint_0(
    const float axis_x,
    const float axis_y,
    const float theta_degrees
) {
    endpoint_0->rotate_around(
        axis_x,
        axis_y,
        theta_degrees
    );
}

void Line2D::rotate_endpoint_1(
    const float axis_x,
    const float axis_y,
    const float theta_degrees
) {
    endpoint_1->rotate_around(
        axis_x,
        axis_y,
        theta_degrees
    );
}

} // end of namespace djf_3d
