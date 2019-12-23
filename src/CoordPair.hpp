namespace djf_3d {

class CoordPair {

private:
    float x_pos;
    float y_pos;

public:
    /**
     * The constructor for a CoordPair.
     *
     * @param x the x-coordinate
     * @param y the y-coordinate
     */
    CoordPair(
        const float x,
        const float y
    ) noexcept;

    /**
     * The destructor for a CoordPair.
     */
    ~CoordPair(void) noexcept;

    /**
     * Getter for the x-coordinate.
     *
     * @return x-coordinate of this CoordPair
     */
    float get_x_pos(void) const noexcept;

    /**
     * Getter for the y-coordinate.
     *
     * @return y-coordinate of this CoordPair
     */
    float get_y_pos(void) const noexcept;

    /**
     * This method translates the CoordPair along the x-axis.
     *
     * @param amount the amount by which to translate the CoordPair
     */
    void translate_x_pos(const float amount) noexcept;

    /**
     * This method translates the CoordPair along the y-axis.
     *
     * @param amount the amount by which to translate the CoordPair
     */
    void translate_y_pos(const float amount) noexcept;

    /**
     * This method rotates the CoordPair around another CoordPair.
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
     * This method rotates the CoordPair around another CoordPair.
     *
     * @param axis the CoordPair about which to rotate
     * @param theta_degrees number of degrees to rotate
     */
    void rotate_around(
        const CoordPair& axis,
        const float theta_degrees
    ) noexcept;

};

} // end of namespace djf_3d
