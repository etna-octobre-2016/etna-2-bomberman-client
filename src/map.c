#include "headers/game.h"
#include "headers/map.h"

t_map *map_init()
{
  t_map *map;

  map = malloc(sizeof(t_map));
  if (map == NULL)
  {
    return (NULL);
  }
  map->height = 0;
  map->width = 0;
  map->destroy = &map_destroy;
  map->getHeight = &map_get_height;
  map->getWidth = &map_get_width;
  map->setSize = &map_set_size;
  return (map);
}
int map_get_height()
{
  t_game *game;

  game = game_get_data();
  return (game->map->height);
}
int map_get_width()
{
  t_game *game;

  game = game_get_data();
  return (game->map->width);
}
void map_destroy()
{
  t_game *game;

  game = game_get_data();
  free(game->map);
  printf("map destroyed\n");
}
void map_set_size(int height, int width)
{
  t_game *game;

  game = game_get_data();
  game->map->height = height;
  game->map->width = width;
}
