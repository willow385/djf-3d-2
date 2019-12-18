class CoordPair {

private:
    float x_pos;
    float y_pos;

public:
    CoordPair(float x, float y);
    ~CoordPair(void);

    float get_x_pos(void);

    float get_y_pos(void);

    void translate_x_pos(float amount);

    void translate_y_pos(float amount);

    void rotate_around(
        float axis_x,
        float axis_y,
        float radians
    );
}
