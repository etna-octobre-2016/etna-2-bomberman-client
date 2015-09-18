#include <stdio.h>
#include "headers/game.h"

int main()
{
  t_game *game;

  game = game_init();
  if (game != NULL)
  {
    game->start();
    printf("map height = %d\n", game->map->getHeight());
    printf("map width = %d\n", game->map->getWidth());
    game->map->setSize(10, 30);
    printf("map height = %d\n", game->map->getHeight());
    printf("map width = %d\n", game->map->getWidth());
    game->quit();
  }
  return 0;
}
