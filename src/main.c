#include <stdio.h>
#include "headers/game.h"

int main()
{
  t_game *game;

  t_player *p1;
  t_player *p2;

  game = game_init();
  if (game != NULL)
  {
    game->start();
    printf("map height = %d\n", game->map->getHeight());
    printf("map width = %d\n", game->map->getWidth());
    game->map->setSize(10, 30);
    printf("map height = %d\n", game->map->getHeight());
    printf("map width = %d\n", game->map->getWidth());
    game->addPlayer(123);
    game->addPlayer(12);
    p1 = game->getPlayerById(12);
    p2 = game->getPlayerById(123);
    printf("p1 addr = %p\n", p1);
    printf("p2 addr = %p\n", p2);
    game->quit();
  }
  return 0;
}
