#include "CoordPair.h"

#ifndef PERSPECTIVE_H
#define PERSPECTIVE_H
namespace djf_3d {

/* A lot of the code for projecting 3d objects onto
   a flat surface requires a vanishing point and a
   field-of-view value. Passing these as literal values
   is more verbose and less readable, so instead I have
   created a class to explicitly associate them and
   thereby make code clearer. */
class Perspective {
public:
    /* I'm making the data public because there's no
       real benefit to encapsulating it. It's fine for
       the data to be exposed as part of the interface
       here because this is such a simple class. */
    CoordPair vanishing_point;
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