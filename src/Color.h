#ifndef COLOR_H
#define COLOR_H
namespace djf_3d {

/* This struct stores a Color by its red, green, and blue
values. They are stored as uint8_t because they should be
in the range 0..256. */
struct Color {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
};

} // end of namespace djf_3d
#endif // COLOR_H
