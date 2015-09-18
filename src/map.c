#include "headers/map.h"

static t_map *g_map; // TODO: replace this global variable

t_map *map_init()
{
  g_map = malloc(sizeof(t_map));
  if (g_map == NULL)
  {
    return NULL;
  }
  g_map->height = 0;
  g_map->width = 0;
  g_map->getHeight = &map_get_height;
  g_map->getWidth = &map_get_width;
  g_map->setSize = &map_set_size;
  return g_map;
}
int map_get_height()
{
  return g_map->height;
}
int map_get_width()
{
  return g_map->width;
}
void map_destroy()
{
  printf("map destroyed\n");
  free(g_map);
}
void map_set_size(int height, int width)
{
  g_map->height = height;
  g_map->width = width;
}
