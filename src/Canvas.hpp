#ifndef MEMORY
#define MEMORY
#include <memory>
#endif

#ifndef SDL2_SDL_H
#define SDL2_SDL_H
#include <SDL2/SDL.h>
#endif

namespace djf_3d {

class Canvas {

private:
    SDL_Window *main_window;
    SDL_Renderer *renderer;
    SDL_Event event;

public:
    /**
     * Constructor for the Canvas class.
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
    ~Canvas(void);

    /**
     * This function refreshes the window. The result of calling the
     * drawing methods will show up when this method is called.
     */
    void refresh(void);

    /**
     * This method will return true if, when it is called, the user
     * presses the X key or clicks the close button; otherwise it will
     * return false.
     *
     * @return true if the user tries to close the window, else false
     */
    bool exit(void);

    /**
     * This method will change the color of whatever is drawn on the
     * canvas after it is called.
     *
     * @param r the red portion of the color
     * @param g the green portion of the color
     * @param b the blue portion of the color
     */
    void set_draw_color(const int r, const int g, const int b);

    /**
     * This method will draw a single point at (x, y) in whatever color was
     * picked by the last call to set_draw_color().
     *
     * @param x the x-position
     * @param y the y-position
     */
    void draw_point(const int x, const int y);

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
    );

    /**
     * This method will set every pixel in the window to whatever color
     * was picked by the most recent call to set_draw_color().
     */
    void fill_window(void);
};

} // end of namespace djf_3d
