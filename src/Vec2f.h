#ifndef VEC2F_H
#define VEC2F_H

namespace djf_3d {

class Vec2f {

private:
    float x_pos;
    float y_pos;

public:
    /**
     * The constructor for a Vec2f.
     *
     * @param x the x-coordinate
     * @param y the y-coordinate
     */
    Vec2f(
        const float x,
        const float y
    ) noexcept;

    /**
     * The destructor for a Vec2f.
     */
    ~Vec2f(void) noexcept;

    /**
     * Getter for the x-coordinate.
     *
     * @return x-coordinate of this Vec2f
     */
    float get_x_pos(void) const noexcept;

    /**
     * Getter for the y-coordinate.
     *
     * @return y-coordinate of this Vec2f
     */
    float get_y_pos(void) const noexcept;

    /**
     * This method translates the Vec2f along the x-axis.
     *
     * @param amount the amount by which to translate the Vec2f
     */
    void translate_x_pos(const float amount) noexcept;

    /**
     * This method translates the Vec2f along the y-axis.
     *
     * @param amount the amount by which to translate the Vec2f
     */
    void translate_y_pos(const float amount) noexcept;

    /**
     * This method rotates the Vec2f around another Vec2f.
     *
     * @param axis_x the x-coordinate of the point about which to rotate
     * @param axis_y the y-coordinate of the point about which to rotate
     * @param theta_degrees number of degrees to rotate
     */
    void rotate_around(
        const float axis_x,
        const float axis_y,
        const float theta_degrees
    ) noexcept;

    /**
     * This method rotates the Vec2f around another Vec2f.
     *
     * @param axis the Vec2f about which to rotate
     * @param theta_degrees number of degrees to rotate
     */
    void rotate_around(
        const Vec2f& axis,
        const float theta_degrees
    ) noexcept;

};

} // end of namespace djf_3d

#endif // VEC2F_H