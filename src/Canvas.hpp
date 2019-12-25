#ifndef COORDPAIR_HPP
#define COORDPAIR_HPP
#include "CoordPair.hpp"
#endif

#ifndef COORDTRIPLE_HPP
#define COORDTRIPLE_HPP
#include "CoordTriple.hpp"
#endif

#ifndef PERSPECTIVE_HPP
#define PERSPECTIVE_HPP
#include "Perspective.hpp"
#endif

#ifndef KEYBOARDSTATE_HPP
#define KEYBOARDSTATE_HPP
#include "KeyboardState.hpp"
#endif

#ifndef MODEL3D_HPP
#define MODEL3D_HPP
#include "Model3d.hpp"
#endif

struct SDL_Window;
struct SDL_Renderer;
union SDL_Event;

namespace djf_3d {

class Canvas {

private:
    SDL_Window *main_window;
    SDL_Renderer *renderer;
    SDL_Event *event;
    int width_px;
    int height_px;

public:
    /**
     * Constructor for the Canvas class.
     *
     * This will throw an exception if it can't create a
     * window for whatever reason (for example, if you try
     * to run it without a windowing system).
     *
     * @param title the text to display in the titlebar
     * @param width the width of the window in pixels
     * @param height the height of the window in pixels
     */
    Canvas(
        const std::string& title,
        const int width,
        const int height
    );

    /**
     * Destructor for the Canvas class.
     */
    ~Canvas(void) noexcept;

    /**
     * This function refreshes the window. The result of calling the
     * drawing methods will show up when this method is called.
     */
    void refresh(void) noexcept;

    /**
     * This method returns the width of the Canvas in pixels.
     *
     * @return width of the Canvas
     */
    int get_width(void);

    /**
     * This method returns the height of the Canvas in pixels.
     *
     * @return height of the Canvas
     */
    int get_height(void);

    /**
     * This method will return true if, when it is called, the user
     * clicks the close button; otherwise it will return false.
     *
     * @return true if the user tries to close the window, else false
     */
    bool exit(void) noexcept;

    /**
     * This method gets the current state of the keyboard. See the
     * file "KeyboardState.hpp" for more details.
     *
     * @return KeyboardState describing which keys are pressed
     */
    KeyboardState get_keyboard_state(void) noexcept;

    /**
     * This method will change the color of whatever is drawn on the
     * canvas after it is called.
     *
     * @param r the red portion of the color
     * @param g the green portion of the color
     * @param b the blue portion of the color
     */
    void set_draw_color(
        const int r,
        const int g,
        const int b
    ) noexcept;

    /**
     * This method will draw a single point at (x, y) in whatever color was
     * picked by the last call to set_draw_color().
     *
     * @param x the x-position
     * @param y the y-position
     */
    void draw_point(
        const int x,
        const int y
    ) noexcept;

    /**
     * This method will draw a djf::CoordPair in the color
     * picked by the last call to set_draw_color().
     *
     * @param point the djf_3d::CoordPair to draw a point at
     */
    void draw_point(
        const CoordPair& point
    ) noexcept;

    /**
     * This method will draw a djf::CoordTriple in the color
     * picked by the last call to set_draw_color(), projected
     * according to a vanishing point and field of view.
     *
     * @param point the djf_3d::CoordTriple to draw
     * @param vanish_point djf_3d::CoordPair where lines converge
     * @param fov the degree to which a point appears distorted by perspective
     */
    void draw_point(
        const CoordTriple& point,
        const CoordPair& vanish_point,
        const float fov
    ) noexcept;

    /**
     * This method will draw a djf::CoordTriple in the color
     * picked by the last call to set_draw_color(), projected
     * according to a vanishing point and field of view.
     *
     * @param point the djf_3d::CoordTriple to draw
     * @param perspective a Perspective
     */
    void draw_point(
        const CoordTriple& point,
        const Perspective& perspective
    ) noexcept;

    /**
     * This method will draw a straight line from (x0, y0) to (x1, y1)
     * in whatever color was picked by the most recent call to
     * set_draw_color().
     *
     * @param x0 the x-coordinate of the first endpoint
     * @param y0 the y-coordinate of the first endpoint
     * @param x1 the x-coordinate of the second endpoint
     * @param y1 the y-coordinate of the second endpoint
     */
    void draw_line(
        const int x0,
        const int y0,
        const int x1,
        const int y1
    ) noexcept;

    /**
     * This method will draw a straight line between two CoordPairs
     * in whatever color was picked by the most recent call to
     * set_draw_color().
     *
     * @param point_0 the first endpoint
     * @param point_1 the second endpoint
     */
    void draw_line(
        const CoordPair& point_0,
        const CoordPair& point_1
    ) noexcept;

    /**
     * This method will draw a straight line betwen two CoordTriples
     * according to the Perspective passed to it.
     *
     * @param point_0 the first endpoint
     * @param point_1 the second endpoint
     * @param perspective a Perspective
     */
    void draw_line(
        const CoordTriple& point_0,
        const CoordTriple& point_1,
        const Perspective& perspective
    ) noexcept;

    /**
     * This method will set every pixel in the window to whatever color
     * was picked by the most recent call to set_draw_color().
     */
    void fill_window(void) noexcept;

    /**
     * This method will draw a Model3d.
     *
     * @param model the 3d model to draw
     * @param persp a Perspective
     */
    void draw_model3d(
        const Model3d& model,
        const Perspective& persp
    ) noexcept;
};

} // end of namespace djf_3d
