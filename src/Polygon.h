#include <vector>
#include "CoordTriple.h"

#ifndef POLYGON_H
#define POLYGON_H

namespace djf_3d {

struct Polygon {
    /* These are non-owning pointers that the Polygon
       is not responsible for freeing. */
    std::vector<const CoordTriple *> vertices;
};

}

#endif