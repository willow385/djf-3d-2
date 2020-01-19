#include "Canvas.h"
#include "TextRenderer.h"

namespace djf_3d {

void TextRenderer::render_char(
    Canvas& canvas,
    int x,
    int y,
    const char character
) const noexcept {
    /* Every character is 8 pixels tall and 5 pixels wide.
       Upon encountering an unrecognized character, it
       displays a highlighted question mark. */
    switch (character) {
        case ' ':
            break;
        case '!':
            canvas.draw_line(x+2, y, x+2, y+5);
            canvas.draw_point(x+2, y+7);
            break;
        case '"':
            canvas.draw_line(x+1, y, x+1, y+2);
            canvas.draw_line(x+3, y, x+3, y+2);
            break;
        case '#':
            canvas.draw_line(x+1, y, x+1, y+8);
            canvas.draw_line(x+3, y, x+3, y+8);
            canvas.draw_line(x, y+2, x+5, y+2);
            canvas.draw_line(x, y+5, x+5, y+5);
            break;
        case '$':
            canvas.draw_line(x+1, y, x+4, y);
            canvas.draw_line(x, y+1, x, y+2);
            canvas.draw_line(x+4, y+5, x+4, y+7);
            canvas.draw_line(x+1, y+7, x+4, y+7);
            canvas.draw_line(x, y+2, x+4, y+5);
            canvas.draw_point(x+4, y+1);
            canvas.draw_point(x, y+6);
            canvas.draw_line(x+2, y-1, x+2, y+9);
            break;
        case '%':
            canvas.draw_line(x+4, y+2, x, y+5);
            canvas.draw_point(x+1, y);
            canvas.draw_point(x, y+1);
            canvas.draw_point(x+2, y+1);
            canvas.draw_point(x+1, y+2);
            canvas.draw_point(x+3, y+7);
            canvas.draw_point(x+4, y+6);
            canvas.draw_point(x+2, y+6);
            canvas.draw_point(x+3, y+5);
            break;
        case '&':
            canvas.draw_point(x+3, y+1);
            canvas.draw_line(x+1, y, x+2, y);
            canvas.draw_line(x, y+1, x, y+3);
            canvas.draw_line(x+1, y+4, x+4, y+7);
            canvas.draw_line(x+1, y+7, x+4, y+4);
            canvas.draw_line(x, y+5, x, y+6);
            break;
        case '\'':
            canvas.draw_line(x+2, y, x+2, y+1);
            break;
        case '(':
            canvas.draw_line(x+3, y, x+1, y+2);
            canvas.draw_line(x+1, y+5, x+3, y+7);
            canvas.draw_line(x+1, y+2, x+1, y+5);
            break;
        case ')':
            canvas.draw_line(x+1, y, x+3, y+2);
            canvas.draw_line(x+3, y+5, x+1, y+7);
            canvas.draw_line(x+3, y+2, x+3, y+5);
            break;
        case '*':
            canvas.draw_line(x+1, y, x+3, y+4);
            canvas.draw_line(x+3, y, x+1, y+4);
            canvas.draw_line(x, y+2, x+4, y+2);
            break;
        case '+':
            canvas.draw_line(x+2, y+1, x+2, y+5);
            canvas.draw_line(x, y+3, x+4, y+3);
            break;
        case ',':
            canvas.draw_line(x+2, y+5, x+2, y+7);
            canvas.draw_line(x+1, y+5, x+1, y+6);
            canvas.draw_point(x+1, y+8);
            break;
        case '-':
            canvas.draw_line(x, y+3, x+4, y+3);
            break;
        case '.':
            canvas.draw_line(x+1, y+6, x+2, y+7);
            canvas.draw_line(x+1, y+7, x+2, y+6);
            break;
        case '/':
            canvas.draw_line(x, y+7, x+4, y);
            break;
        case '0':
            canvas.draw_line(x+2, y, x, y+2);
            canvas.draw_line(x+2, y, x+4, y+2);
            canvas.draw_line(x, y+3, x, y+6);
            canvas.draw_line(x+4, y+3, x+4, y+6);
            canvas.draw_line(x, y+6, x+2, y+7);
            canvas.draw_line(x+4, y+6, x+2, y+7);
            canvas.draw_line(x, y+6, x+4, y+2);
            canvas.draw_point(x+4, y+2);
            break;
        case '1':
            canvas.draw_line(x, y, x+2, y);
            canvas.draw_line(x+2, y, x+2, y+6);
            canvas.draw_line(x, y+7, x+4, y+7);
            break;
        case '2':
            canvas.draw_line(x, y+1, x+1, y);
            canvas.draw_line(x+1, y, x+3, y);
            canvas.draw_line(x+3, y, x+4, y+1);
            canvas.draw_line(x+4, y+1, x+4, y+3);
            canvas.draw_line(x+4, y+3, x, y+7);
            canvas.draw_line(x, y+7, x+4, y+7);
            break;
        case '3':
            canvas.draw_line(x, y+1, x+1, y);
            canvas.draw_line(x+1, y, x+3, y);
            canvas.draw_line(x+4, y+1, x+4, y+3);
            canvas.draw_line(x+4, y+3, x+2, y+3);
            canvas.draw_line(x+2, y+3, x+4, y+5);
            canvas.draw_line(x+4, y+5, x+4, y+6);
            canvas.draw_line(x+1, y+7, x+3, y+7);
            canvas.draw_line(x, y+6, x+1, y+7);
            break;
        case '4':
            canvas.draw_line(x, y, x, y+4);
            canvas.draw_line(x, y+4, x+4, y+4);
            canvas.draw_line(x+4, y, x+4, y+7);
            break;
        case '5':
            canvas.draw_line(x+4, y, x, y);
            canvas.draw_line(x, y, x, y+4);
            canvas.draw_line(x+1, y+3, x+3, y+3);
            canvas.draw_line(x+4, y+4, x+4, y+6);
            canvas.draw_line(x+3, y+7, x+1, y+7);
            canvas.draw_point(x, y+6);
            break;
        case '6':
            canvas.draw_line(x+3, y, x+1, y);
            canvas.draw_point(x+4, y+1);
            canvas.draw_line(x, y+1, x, y+6);
            canvas.draw_line(x+1, y+7, x+3, y+7);
            canvas.draw_line(x+4, y+6, x+4, y+4);
            canvas.draw_line(x+3, y+3, x+1, y+3);
            break;
        case '7':
            canvas.draw_line(x, y, x, y+1);
            canvas.draw_line(x, y, x+4, y);
            canvas.draw_line(x+4, y, x+3, y+7);
            break;
        case '8':
            canvas.draw_line(x+1, y, x+3, y);
            canvas.draw_line(x, y+1, x, y+2);
            canvas.draw_line(x+1, y+3, x+3, y+3);
            canvas.draw_line(x+4, y+1, x+4, y+2);
            canvas.draw_line(x, y+4, x, y+6);
            canvas.draw_line(x+4, y+4, x+4, y+6);
            canvas.draw_line(x+1, y+7, x+3, y+7);
            break;
        case '9':
            canvas.draw_line(x+1, y, x+3, y);
            canvas.draw_line(x, y+1, x, y+2);
            canvas.draw_line(x+1, y+3, x+3, y+3);
            canvas.draw_line(x+4, y+1, x+4, y+6);
            canvas.draw_line(x+3, y+7, x+1, y+7);
            break;
        case ':':
            canvas.draw_line(x+2, y, x+3, y+1);
            canvas.draw_line(x+2, y+1, x+3, y);
            canvas.draw_line(x+2, y+6, x+3, y+7);
            canvas.draw_line(x+2, y+7, x+3, y+6);
            break;
        case ';':
            canvas.draw_line(x+1, y, x+2, y+1);
            canvas.draw_line(x+1, y+1, x+2, y);
            canvas.draw_line(x+2, y+5, x+2, y+7);
            canvas.draw_line(x+1, y+5, x+1, y+6);
            canvas.draw_point(x+1, y+8);
            break;
        case '<':
            canvas.draw_line(x, y+4, x+4, y+1);
            canvas.draw_line(x, y+4, x+4, y+6);
            break;
        case '=':
            canvas.draw_line(x, y+3, x+4, y+3);
            canvas.draw_line(x, y+5, x+4, y+5);
            break;
        case '>':
            canvas.draw_line(x+4, y+4, x, y+1);
            canvas.draw_line(x+4, y+4, x, y+6);
            break;
        case '?':
            canvas.draw_line(x, y+1, x+1, y);
            canvas.draw_line(x+1, y, x+3, y);
            canvas.draw_line(x+4, y+1, x+4, y+2);
            canvas.draw_line(x+3, y+3, x+2, y+3);
            canvas.draw_line(x+1, y+4, x+1, y+5);
            canvas.draw_point(x+1, y+7);
            break;
        case '@':
            canvas.draw_line(x+1, y, x+4, y);
            canvas.draw_line(x, y+1, x, y+6);
            canvas.draw_line(x+1, y+7, x+4, y+7);
            canvas.draw_line(x+4, y+7, x+4, y+3);
            canvas.draw_line(x+3, y+2, x+2, y+2);
            canvas.draw_line(x+2, y+2, x+2, y+4);
            canvas.draw_line(x+2, y+4, x+4, y+4);
            break;
        case 'A':
            canvas.draw_line(x+2, y, x, y+2);
            canvas.draw_line(x+2, y, x+4, y+2);
            canvas.draw_point(x+0, y+3);
            canvas.draw_point(x+4, y+2);
            canvas.draw_point(x+4, y+3);
            canvas.draw_line(x, y+4, x+4, y+4);
            canvas.draw_line(x, y+4, x, y+8);
            canvas.draw_line(x+4, y+4, x+4, y+8);
            break;
        case 'B':
            canvas.draw_line(x, y, x+4, y);
            canvas.draw_line(x, y, x, y+7);
            canvas.draw_line(x, y+3, x+4, y+3);
            canvas.draw_line(x, y+7, x+4, y+7);
            canvas.draw_line(x+4, y+1, x+4, y+3);
            canvas.draw_line(x+4, y+4, x+4, y+7);
            break;
        case 'C':
            canvas.draw_line(x+1, y, x+4, y);
            canvas.draw_line(x, y+1, x, y+7);
            canvas.draw_line(x+1, y+7, x+4, y+7);
            break;
        case 'D':
            canvas.draw_line(x+4, y, x, y);
            canvas.draw_line(x+4, y+1, x+4, y+7);
            canvas.draw_line(x+4, y+7, x, y+7);
            canvas.draw_line(x, y, x, y+7);
            break;
        case 'E':
            canvas.draw_line(x, y, x, y+7);
            canvas.draw_line(x, y, x+4, y);
            canvas.draw_line(x, y+3, x+4, y+3);
            canvas.draw_line(x, y+7, x+4, y+7);
            break;
        case 'F':
            canvas.draw_line(x, y, x, y+8);
            canvas.draw_line(x, y, x+4, y);
            canvas.draw_line(x, y+3, x+4, y+3);
            break;
        case 'G':
            canvas.draw_line(x+1, y, x+4, y);
            canvas.draw_line(x, y+1, x, y+7);
            canvas.draw_line(x+1, y+7, x+4, y+7);
            canvas.draw_line(x+4, y+7, x+4, y+3);
            break;
        case 'H':
            canvas.draw_line(x, y, x, y+8);
            canvas.draw_line(x, y+3, x+4, y+3);
            canvas.draw_line(x+4, y, x+4, y+8);
            break;
        case 'I':
            canvas.draw_line(x, y, x+5, y);
            canvas.draw_line(x+2, y, x+2, y+7);
            canvas.draw_line(x, y+7, x+5, y+7);
            break;
        case 'J':
            canvas.draw_line(x, y, x+4, y);
            canvas.draw_line(x+3, y, x+3, y+7);
            canvas.draw_point(x+2, y+7);
            canvas.draw_point(x+1, y+7);
            canvas.draw_point(x, y+6);
            break;
        case 'K':
            canvas.draw_line(x, y, x, y+8);
            canvas.draw_line(x, y+3, x+4, y-1);
            canvas.draw_line(x, y+3, x+4, y+8);
            break;
        case 'L':
            canvas.draw_line(x, y, x, y+7);
            canvas.draw_line(x, y+7, x+4, y+7);
            break;
        case 'M':
            canvas.draw_line(x, y, x, y+8);
            canvas.draw_line(x+4, y, x+4, y+8);
            canvas.draw_line(x, y, x+3, y+3);
            canvas.draw_line(x+4, y, x+2, y+3);
            break;
        case 'N':
            canvas.draw_line(x, y, x, y+8);
            canvas.draw_line(x+4, y, x+4, y+8);
            canvas.draw_line(x, y, x+4, y+8);
            break;
        case 'O':
            canvas.draw_line(x+2, y, x, y+2);
            canvas.draw_line(x+2, y, x+4, y+2);
            canvas.draw_line(x, y+3, x, y+5);
            canvas.draw_line(x+4, y+2, x+4, y+6);
            canvas.draw_line(x, y+5, x+2, y+7);
            canvas.draw_line(x+4, y+5, x+2, y+7);
            break;
        case 'P':
            canvas.draw_line(x, y, x, y+8);
            canvas.draw_line(x, y, x+4, y);
            canvas.draw_line(x, y+3, x+4, y+3);
            canvas.draw_line(x+4, y+1, x+4, y+3);
            break;
        case 'Q':
            canvas.draw_line(x+2, y, x, y+2);
            canvas.draw_line(x+2, y, x+4, y+2);
            canvas.draw_line(x, y+3, x, y+5);
            canvas.draw_line(x+4, y+2, x+4, y+5);
            canvas.draw_line(x, y+5, x+2, y+7);
            canvas.draw_line(x+4, y+5, x+2, y+7);
            canvas.draw_line(x+2, y+4, x+5, y+8);
            break;
        case 'R':
            canvas.draw_line(x, y, x, y+8);
            canvas.draw_line(x, y, x+4, y);
            canvas.draw_line(x, y+3, x+4, y+3);
            canvas.draw_line(x+4, y+1, x+4, y+3);
            canvas.draw_line(x, y+3, x+4, y+8);
            break;
        case 'S':
            canvas.draw_line(x+1, y, x+4, y);
            canvas.draw_line(x, y+1, x, y+2);
            canvas.draw_line(x+4, y+5, x+4, y+7);
            canvas.draw_line(x+1, y+7, x+4, y+7);
            canvas.draw_line(x, y+2, x+4, y+5);
            canvas.draw_point(x+4, y+1);
            canvas.draw_point(x, y+6);
            break;
        case 'T':
            canvas.draw_line(x, y, x+5, y);
            canvas.draw_line(x+2, y, x+2, y+8);
            break;
        case 'U':
            canvas.draw_line(x, y, x, y+7);
            canvas.draw_line(x+4, y, x+4, y+7);
            canvas.draw_line(x+1, y+7, x+4, y+7);
            break;
        case 'V':
            canvas.draw_line(x, y, x+2, y+8);
            canvas.draw_line(x+4, y, x+2, y+8);
            break;
        case 'W':
            canvas.draw_line(x, y, x, y+7);
            canvas.draw_point(x+1, y+7);
            canvas.draw_line(x+2, y, x+2, y+7);
            canvas.draw_point(x+3, y+7);
            canvas.draw_line(x+4, y, x+4, y+7);
            break;
        case 'X':
            canvas.draw_line(x, y, x, y+2);
            canvas.draw_line(x+4, y, x+4, y+3);
            canvas.draw_line(x, y+2, x+4, y+5);
            canvas.draw_line(x+4, y+2, x, y+5);
            canvas.draw_line(x, y+5, x, y+8);
            canvas.draw_line(x+4, y+5, x+4, y+8);
            break;
        case 'Y':
            canvas.draw_line(x, y, x, y+2);
            canvas.draw_line(x+4, y, x+4, y+3);
            canvas.draw_line(x, y+2, x+2, y+4);
            canvas.draw_line(x+4, y+2, x+2, y+4);
            canvas.draw_line(x+2, y+4, x+2, y+8);
            break;
        case 'Z':
            canvas.draw_line(x, y, x+4, y);
            canvas.draw_line(x+4, y, x, y+7);
            canvas.draw_line(x, y+7, x+5, y+7);
            break;
        case '[':
            canvas.draw_line(x, y, x+3, y);
            canvas.draw_line(x, y, x, y+7);
            canvas.draw_line(x, y+7, x+3, y+7);
            break;
        case '\\':
            canvas.draw_line(x, y, x+4, y+7);
            break;
        case ']':
            canvas.draw_line(x+1, y, x+4, y);
            canvas.draw_line(x+4, y, x+4, y+7);
            canvas.draw_line(x+1, y+7, x+4, y+7);
            break;
        case '^':
            canvas.draw_line(x, y+2, x+2, y);
            canvas.draw_line(x+2, y, x+4, y+2);
            break;
        case '_':
            canvas.draw_line(x, y+7, x+4, y+7);
            break;
        case '`':
            canvas.draw_line(x+1, y, x+3, y+2);
            break;
        case 'a':
            canvas.draw_line(x+4, y+7, x+4, y+3);
            canvas.draw_line(x+3, y+2, x, y+2);
            canvas.draw_line(x+3, y+4, x+1, y+4);
            canvas.draw_line(x, y+5, x, y+6);
            canvas.draw_line(x+1, y+7, x+4, y+7);
            break;
        case 'b':
            canvas.draw_line(x, y, x, y+7);
            canvas.draw_line(x+1, y+2, x+3, y+2);
            canvas.draw_line(x+4, y+3, x+4, y+6);
            canvas.draw_line(x+1, y+7, x+3, y+7);
            break;
        case 'c':
            canvas.draw_line(x+4, y+2, x+1, y+2);
            canvas.draw_line(x, y+3, x, y+6);
            canvas.draw_line(x+1, y+7, x+4, y+7);
            break;
        case 'd':
            canvas.draw_line(x+4, y, x+4, y+7);
            canvas.draw_line(x+3, y+2, x+1, y+2);
            canvas.draw_line(x, y+3, x, y+6);
            canvas.draw_line(x+3, y+7, x+1, y+7);
            break;
        case 'e':
            canvas.draw_line(x+1, y+2, x+3, y+2);
            canvas.draw_line(x, y+3, x, y+6);
            canvas.draw_line(x, y+4, x+4, y+4);
            canvas.draw_point(x+4, y+3);
            canvas.draw_line(x+1, y+7, x+4, y+7);
            break;
        case 'f':
            canvas.draw_line(x, y+1, x, y+7);
            canvas.draw_line(x+1, y, x+3, y);
            canvas.draw_point(x+4, y+1);
            canvas.draw_line(x, y+3, x+3, y+3);
            break;
        case 'g':
            canvas.draw_line(x+1, y+2, x+4, y+2);
            canvas.draw_line(x+4, y+3, x+4, y+8);
            canvas.draw_line(x, y+3, x, y+6);
            canvas.draw_line(x+1, y+7, x+3, y+7);
            canvas.draw_line(x, y+9, x+3, y+9);
            break;
        case 'h':
            canvas.draw_line(x, y, x, y+7);
            canvas.draw_line(x+1, y+2, x+3, y+2);
            canvas.draw_line(x+4, y+3, x+4, y+7);
            break;
        case 'i':
            canvas.draw_line(x, y+2, x+2, y+2);
            canvas.draw_line(x+2, y+2, x+2, y+6);
            canvas.draw_line(x+3, y+7, x+4, y+7);
            canvas.draw_point(x+2, y);
            break;
        case 'j':
            canvas.draw_line(x, y+2, x+2, y+2);
            canvas.draw_line(x+2, y+2, x+2, y+8);
            canvas.draw_point(x+2, y);
            canvas.draw_point(x+1, y+9);
            break;
        case 'k':
            canvas.draw_line(x, y, x, y+7);
            canvas.draw_line(x, y+5, x+4, y+2);
            canvas.draw_line(x, y+4, x+4, y+7);
            break;
        case 'l':
            canvas.draw_line(x, y, x+2, y);
            canvas.draw_line(x+2, y, x+2, y+6);
            canvas.draw_line(x+3, y+7, x+4, y+7);
            break;
        case 'm':
            canvas.draw_line(x, y+2, x, y+7);
            canvas.draw_point(x+1, y+2);
            canvas.draw_line(x+2, y+3, x+2, y+7);
            canvas.draw_point(x+3, y+2);
            canvas.draw_line(x+4, y+3, x+4, y+7);
            break;
        case 'n':
            canvas.draw_line(x, y+2, x, y+7);
            canvas.draw_line(x, y+2, x+3, y+2);
            canvas.draw_line(x+4, y+3, x+4, y+7);
            break;
        case 'o':
            canvas.draw_line(x+1, y+2, x+3, y+2);
            canvas.draw_line(x, y+3, x, y+6);
            canvas.draw_line(x+1, y+7, x+3, y+7);
            canvas.draw_line(x+4, y+3, x+4, y+6);
            break;
        case 'p':
            canvas.draw_line(x+1, y+2, x+3, y+2);
            canvas.draw_line(x, y+3, x, y+9);
            canvas.draw_line(x+1, y+7, x+3, y+7);
            canvas.draw_line(x+4, y+3, x+4, y+6);
            break;
        case 'q':
            canvas.draw_line(x+1, y+2, x+3, y+2);
            canvas.draw_line(x, y+3, x, y+6);
            canvas.draw_line(x+1, y+7, x+3, y+7);
            canvas.draw_line(x+4, y+3, x+4, y+9);
            break;
        case 'r':
            canvas.draw_line(x, y+3, x, y+7);
            canvas.draw_line(x+1, y+2, x+4, y+2);
            break;
        case 's':
            canvas.draw_line(x+1, y+2, x+4, y+2);
            canvas.draw_point(x, y+3);
            canvas.draw_line(x+1, y+4, x+3, y+4);
            canvas.draw_line(x+4, y+5, x+4, y+6);
            canvas.draw_line(x, y+7, x+3, y+7);
            break;
        case 't':
            canvas.draw_line(x, y, x, y+6);
            canvas.draw_line(x+1, y+2, x+3, y+2);
            canvas.draw_line(x+1, y+7, x+4, y+7);
            break;
        case 'u':
            canvas.draw_line(x, y+2, x, y+6);
            canvas.draw_line(x+1, y+7, x+4, y+7);
            canvas.draw_line(x+4, y+2, x+4, y+7);
            break;
        case 'v':
            canvas.draw_line(x, y+2, x+2, y+7);
            canvas.draw_line(x+4, y+2, x+2, y+7);
            break;
        case 'w':
            canvas.draw_line(x, y+2, x, y+6);
            canvas.draw_point(x+1, y+7);
            canvas.draw_line(x+2, y+2, x+2, y+6);
            canvas.draw_point(x+3, y+7);
            canvas.draw_line(x+4, y+2, x+4, y+7);
            break;
        case 'x':
            canvas.draw_line(x, y+2, x+4, y+7);
            canvas.draw_line(x+4, y+2, x, y+7);
            break;
        case 'y':
            canvas.draw_line(x+4, y+2, x+4, y+8);
            canvas.draw_line(x, y+2, x, y+6);
            canvas.draw_line(x+1, y+7, x+3, y+7);
            canvas.draw_line(x, y+9, x+3, y+9);
            break;
        case 'z':
            canvas.draw_line(x, y+2, x+4, y+2);
            canvas.draw_line(x+4, y+2, x, y+7);
            canvas.draw_line(x, y+7, x+4, y+7);
            break;
        case '{':
            canvas.draw_line(x+3, y, x+4, y);
            canvas.draw_line(x+2, y+1, x+2, y+2);
            canvas.draw_line(x, y+3, x+1, y+3);
            canvas.draw_line(x, y+4, x+1, y+4);
            canvas.draw_line(x+2, y+5, x+2, y+6);
            canvas.draw_line(x+3, y+7, x+4, y+7);
            break;
        case '|':
            canvas.draw_line(x+2, y, x+2, y+7);
            break;
        case '}':
            canvas.draw_line(x+1, y, x, y);
            canvas.draw_line(x+2, y+1, x+2, y+2);
            canvas.draw_line(x+3, y+3, x+4, y+3);
            canvas.draw_line(x+3, y+4, x+4, y+4);
            canvas.draw_line(x+2, y+5, x+2, y+6);
            canvas.draw_line(x, y+7, x+1, y+7);
            break;
        case '~':
            canvas.draw_point(x, y+2);
            canvas.draw_line(x+1, y+1, x+3, y+3);
            canvas.draw_point(x+4, y+2);
            break;
        default:
            canvas.draw_line(x, y, x, y+7);
            canvas.draw_line(x, y, x+4, y);
            canvas.draw_line(x+4, y, x+4, y+7);
            canvas.draw_line(x, y+7, x+4, y+7);
            canvas.draw_point(x+3, y+1);
            canvas.draw_point(x+1, y+2);
            canvas.draw_point(x+2, y+2);
            canvas.draw_point(x+1, y+3);
            canvas.draw_point(x+3, y+3);
            canvas.draw_point(x+1, y+4);
            canvas.draw_point(x+3, y+4);
            canvas.draw_line(x+1, y+5, x+3, y+5);
            canvas.draw_point(x+1, y+6);
            canvas.draw_point(x+3, y+6);
            break;
    }
}

void TextRenderer::render_string(
    Canvas& canvas,
    int x, /* top-left corner of the string */
    int y,
    const char *string
) const noexcept {
    for (int i = 0; string[i]; i++) {
        this->render_char(
            canvas,
            x+(6*i),
            y,
            string[i]
        );
    }
}

} // end of namespace djf_3d