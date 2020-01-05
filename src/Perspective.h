#include "Vec2f.h"

#ifndef PERSPECTIVE_H
#define PERSPECTIVE_H
namespace djf_3d {

/* A lot of the code for projecting 3d objects onto
   a flat surface requires a vanishing point and a
   field-of-view value. Passing these as literal values
   is more verbose and less readable, so instead I have
   created a struct to explicitly associate them and
   thereby make code clearer. */
struct Perspective {

    Vec2f vanishing_point;
    float fov;

    Perspective(
        float vp_x,
        float vp_y,
        float fov_val
    ) noexcept;

    ~Perspective(void) noexcept;
};

} // end of namespace djf_3d
#endif // PERSPECTIVE_H