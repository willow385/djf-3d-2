#include "Canvas.h"

#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H

namespace djf_3d {

class TextRenderer {
public:

    /**
     * Draws a single ASCII char on the canvas at (x, y).
     */
    void render_char(
        Canvas& canvas,
        float x,
        float y,
        const char character
    ) const noexcept;

    /**
     * Writes a null-terminated char array on the canvas
     * starting at (x, y).
     */
    void render_string(
        Canvas& canvas,
        float x,
        float y,
        const char *string
    ) const noexcept;
};

} // end of namespace djf_3d

#endif // TEXTRENDERER_H