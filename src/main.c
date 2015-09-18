#include <stdio.h>
#include "headers/game.h"

int main()
{
  t_game *game;

  game = game_init();
  if (game != NULL)
  {
    game->start();
    game->quit();
  }
  return 0;
}
