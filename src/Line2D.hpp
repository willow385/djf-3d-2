#ifndef COORDPAIR_HPP
#define COORDPAIR_HPP
#include "CoordPair.hpp"
#endif

namespace djf_3d {

class Line2D {

private:
    CoordPair *endpoint_0;
    CoordPair *endpoint_1;

public:
    /**
     * Constructor for a Line2D.
     *
     * @param x0 the x-coordinate of the first endpoint
     * @param y0 the y-coordinate of the first endpoint
     * @param x1 the x-coordinate of the second endpoint
     * @param y1 the y-coordinate of the second endpoint
     */
    Line2D(
        const float x0,
        const float y0,
        const float x1,
        const float y1
    );

    /**
     * Destructor for a Line2D.
     */
    ~Line2D(void);

    /**
     * Getter for the x-coordinate of the first endpoint.
     *
     * @return x-coordinate of the first endpoint
     */
    float get_endpoint_0_x(void) const;

    /**
     * Getter for the y-coordinate of the first endpoint.
     *
     * @return y-coordinate of the first endpoint
     */
    float get_endpoint_0_y(void) const;

    /**
     * Getter for the x-coordinate of the second endpoint.
     *
     * @return x-coordinate of the second endpoint
     */
    float get_endpoint_1_x(void) const;

    /**
     * Getter for the y-coordinate of the second endpoint.
     *
     * @return y-coordinate of the second endpoint
     */
    float get_endpoint_1_y(void) const;

    /**
     * Method to rotate the first endpoint around another point.
     *
     * @param axis_x the x-coordinate of the point about which to rotate
     * @param axis_y the y-coordinate of the point about which to rotate
     * @param theta_degrees number of degrees to rotate
     */
    void rotate_endpoint_0(
        const float axis_x,
        const float axis_y,
        const float theta_degrees
    );

    /**
     * Method to rotate the second endpoint around another point.
     *
     * @param axis_x the x-coordinate of the point about which to rotate
     * @param axis_y the y-coordinate of the point about which to rotate
     * @param theta_degrees number of degrees to rotate
     */
    void rotate_endpoint_1(
        const float axis_x,
        const float axis_y,
        const float theta_degrees
    );

};

} // end of namespace djf_3d
