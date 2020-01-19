#include <djf-3d-2/djf-3d.h>

int main(void) {
    djf_3d::Canvas canvas("foo", 300, 300, 300);
    djf_3d::TextRenderer tr;
    while (!canvas.exit()) {
        canvas.set_draw_color(255, 255, 255, 255);
        canvas.fill_window();
        canvas.set_draw_color(0, 0, 0, 0);
        tr.render_string(
            canvas,
            10,
            10,
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        );
        tr.render_string(
            canvas,
            10,
            25,
            "abcdefghijklmnopqrstuvwxyz"
        );
        tr.render_string(
            canvas,
            10,
            40,
            "~!@#$%^&*()_+`1234567890-={}|[]\\:;\"'<>,.?/"
        );
        canvas.refresh();
    }
    return 0;
}