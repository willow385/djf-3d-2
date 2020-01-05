#include "Perspective.h"
#include "Vec2f.h"

#ifndef VEC3F_H
#define VEC3F_H
namespace djf_3d {

enum class Axis {
    X = 0, // left/right axis (horizontal, paralell to screen)
    Y = 1, // near/far axis (horizontal, perpendicular to screen)
    Z = 2  // up/down axis (vertical)
};

class Vec3f {
private:
    float components[3];

public:
    Vec3f(
        const float x,
        const float y,
        const float z
    ) noexcept;

    ~Vec3f(void) noexcept;

    /**
     * This moves a Vec3f to somewhere else immediately.
     *
     * @param x destination x-coordinate
     * @param y destination y-coordinate
     * @param z destination z-coordinate
     */
    void set_position(
        const float x,
        const float y,
        const float z
    ) noexcept;

    /**
     * This returns the value of one of a Vec3f's
     * properties.
     *
     * @param axis whether the axis is X, Y, or Z
     * @return x_pos, y_pos, or z_pos, according to the axis
     */
    template <Axis axis>
    float get_pos(void) const noexcept;

    /**
     * This translates the Vec3f along one of the axes.
     *
     * @param axis which axis to move along
     * @param distance the amount by which to move
     */
    template <Axis axis>
    void translate(const float distance) noexcept;

    /**
     * This rotates the Vec3f about one of the three axes
     * of three-dimensional space.
     *
     * @param axis which axis to rotate around
     * @param axis_point point to rotate around
     * @param theta_degrees number of degrees to rotate
     */
    template <Axis axis>
    void rotate_3d(
        const Vec3f& axis_point,
        const float theta_degrees
    ) noexcept;


    /* IMPORTANT: REGARDING THE PROJECTION METHODS.

       Pay special note to the value selected for `fov`; this
       parameter specifies the degree to which a point's
       distance from the viewer makes it appear to be closer to
       the vanishing point. Values between 800-1200 are
       recommended; lower than that causes a "fish-eye" effect,
       and higher than that causes things to look exaggeratedly
       flat, like medieval art that lacks perspective. */

    /**
     * This returns the x-position corresponding to the 2d
     * projection of the Vec3f.
     *
     * @param vanish_x 2d x-coordinate of the vanishing point
     * @param fov the field of view
     * @return 2d projection x-coordinate
     */
    float project_2d_x(
        const float vanish_x,
        const float fov
    ) const noexcept;

    /**
     * This returns the x-position corresponding to the 2d
     * projection of the Vec3f.
     *
     * @param perspective a Perspective with vp and fov
     * @return 2d projection x-coordinate
     */
    float project_2d_x(
        const Perspective& perspective
    ) const noexcept;


    /**
     * This returns the y-position corresponding to the 2d
     * projection of the Vec3f.
     *
     * @param vanish_y 2d y-coordinate of the vanishing point
     * @param fov degree of perspective distortion
     * @return 2d projection y-coordinate
     */
    float project_2d_y(
        const float vanish_y,
        const float fov
    ) const noexcept;

    /**
     * This returns the y-position corresponding to the 2d
     * projection of the Vec3f.
     *
     * @param perspective a Perspective with vp and fov
     * @return 2d projection y-coordinate
     */
    float project_2d_y(
        const Perspective& perspective
    ) const noexcept;

    /**
     * This projects the Vec3f into a Vec2f
     * based on a Perspective.
     * @param perspective a Perspective
     * @return 2d projection of the Vec3f
     */
    Vec2f project_2d(
        const Perspective& perspective
    ) const noexcept;
};

} // end of namespace djf_3d

#endif // VEC3F_H