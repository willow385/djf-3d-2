#include "CoordPair.hpp"

class Line2D {

private:
    CoordPair *endpoint_0;
    CoordPair *endpoint_1;

public:
    Line2D(
        float x0,
        float y0,
        float x1,
        float y1
    );

    ~Line2D(void);

    float get_endpoint_0_x(void);

    float get_endpoint_0_y(void);

    float get_endpoint_1_x(void);

    float get_endpoint_1_y(void);

    void rotate_endpoint_0(
        float axis_x,
        float axis_y,
        float theta_degrees
    );

    void rotate_endpoint_1(
        float axis_x,
        float axis_y,
        float theta_degrees
    );

};
