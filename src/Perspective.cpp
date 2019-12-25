#ifndef COORDPAIR_H
#define COORDPAIR_H
#include "CoordPair.h"
#endif

#include "Perspective.h"

namespace djf_3d {

Perspective::Perspective(
    float vp_x,
    float vp_y,
    float fov_val
) noexcept: vanishing_point(vp_x, vp_y) {
    fov = fov_val;
}

Perspective::~Perspective(void) {}

} // end of namespace djf_3d
