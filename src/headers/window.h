#ifndef BOMBERMAN_WINDOW_H
#define BOMBERMAN_WINDOW_H

// INCLUDES
#include <SDL.h>

// CONSTANTS
#define WINDOW_WIDTH  640
#define WINDOW_HEIGHT 480
#define WINDOW_NAME   "Bomberman"

// TYPES
typedef struct  s_window
{
  SDL_Window    *sdl_window;
  SDL_Surface   *sdl_surface;
}               t_window;

// PROTOTYPES
t_window *window_init();

#endif
