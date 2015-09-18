#include "headers/game.h"
#include "headers/map.h"

t_map *map_init()
{
  t_map *map;

  map = malloc(sizeof(t_map));
  if (map == NULL)
  {
    return NULL;
  }
  map->height = 0;
  map->width = 0;
  map->getHeight = &map_get_height;
  map->getWidth = &map_get_width;
  map->setSize = &map_set_size;
  return map;
}
int map_get_height()
{
  t_game  *game;
  t_map   *map;

  game = game_get_data();
  map = game->map;
  return map->height;
}
int map_get_width()
{
  t_game  *game;
  t_map   *map;

  game = game_get_data();
  map = game->map;
  return map->width;
}
void map_destroy()
{
  t_game  *game;
  t_map   *map;

  game = game_get_data();
  map = game->map;
  printf("map destroyed\n");
  free(map);
}
void map_set_size(int height, int width)
{
  t_game  *game;
  t_map   *map;

  game = game_get_data();
  map = game->map;
  map->height = height;
  map->width = width;
}
