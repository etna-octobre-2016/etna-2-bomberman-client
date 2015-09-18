#include "headers/game.h"

static t_game *g_game;

t_game *game_init()
{
  g_game = malloc(sizeof(t_game));
  if (g_game == NULL)
  {
    return NULL;
  }
  g_game->quit = &game_quit;
  g_game->start = &game_start;
  return g_game;

}
void game_quit()
{
  free(g_game);
  printf("game quit\n");
}
void game_start()
{
  printf("game started\n");
}
