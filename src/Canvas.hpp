#ifndef SDL2_SDL_H
#define SDL2_SDL_H
#include <SDL2/SDL.h>
#endif

class Canvas {

private:
    SDL_Window *main_window;
    SDL_Renderer *renderer;
    SDL_Event event;

public:
    Canvas(
        std::string title,
        int width,
        int height
    );

    ~Canvas(void);

};
