#include "headers/window.h"
#include "headers/game.h"

t_window *window_init()
{
  t_window *window;

  window = malloc(sizeof(t_window));
  if (window == NULL)
  {
    fprintf(stderr, "Error during window malloc. %s line %d", __FILE__, __LINE__);
    return (NULL);
  }
  window->sdl_window = NULL;
  window->sdl_surface = NULL;
  window->refresh = &window_refresh;
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    fprintf(stderr, "Error during SDL init. %s line %d", __FILE__, __LINE__);
    return (NULL);
  }
  window->sdl_window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
  if (window->sdl_window == NULL)
  {
    fprintf(stderr, "Error during SDL window creation. %s line %d", __FILE__, __LINE__);
    return (NULL);
  }
  window->sdl_surface = SDL_GetWindowSurface(window->sdl_window);
  return (window);
}
void window_refresh()
{
  t_game *game;

  printf("window refresh\n");
  game = game_get_data();
  SDL_UpdateWindowSurface(game->window->sdl_window);
}
