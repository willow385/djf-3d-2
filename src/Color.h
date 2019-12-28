#ifndef COLOR_H
#define COLOR_H
namespace djf_3d {

/* This struct stores a Color by its red, green, and blue
values. They are stored as uint8_t because they should be
in the range 0..256. */
struct Color {
public:
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

} // end of namespace djf_3d
#endif // COLOR_H
