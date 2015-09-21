#include <stdio.h>
#include "headers/game.h"

int main()
{
  t_game *game;

  t_player *p1;
  t_player *p2;
  t_character *c1;
  t_character *c2;

  game = game_init();
  if (game != NULL)
  {
    game->start();
    while (game->is_running)
    {
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
      c1 = p1->character;
      c2 = p2->character;
      printf("c1 addr = %p\n", c1);
      printf("c2 addr = %p\n", c2);
      c1->backward(c1);
      c1->forward(c1);
      c1->left(c1);
      c1->right(c1);
      c2->backward(c2);
      c2->forward(c2);
      c2->left(c2);
      c2->right(c2);
      game->quit();
    }
    game->destroy();
    printf("game no more running\n");
  }
  return (EXIT_SUCCESS);
}
