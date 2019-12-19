#include "Line2D.hpp"

Line2D::Line2D(
    float x0,
    float y0,
    float x1,
    float y1
) {
    endpoint_0 = new CoordPair(x0, y0);
    endpoint_1 = new CoordPair(x1, y1);
}

Line2D::~Line2D(void) {
    delete endpoint_0;
    delete endpoint_1;
}

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
    float axis_x,
    float axis_y,
    float theta_degrees
) {
    endpoint_0->rotate_around(
        axis_x,
        axis_y,
        theta_degrees
    );
}

void Line2D::rotate_endpoint_1(
    float axis_x,
    float axis_y,
    float theta_degrees
) {
    endpoint_1->rotate_around(
        axis_x,
        axis_y,
        theta_degrees
    );
}
