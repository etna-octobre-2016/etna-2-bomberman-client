#ifndef BOMBERMAN_MAP_H
#define BOMBERMAN_MAP_H

// INCLUDES
#include <stdio.h>
#include <stdlib.h>

// TYPES
typedef struct  s_map
{
  int           height;
  int           width;

  int           (*getHeight)();
  int           (*getWidth)();
  void          (*destroy)();
  void          (*draw)();
  void          (*setSize)(int height, int width);
}               t_map;

// PROTOTYPES
t_map *map_init();
int   map_get_height();
int   map_get_width();
void  map_destroy();
void  map_draw();
void  map_set_size(int height, int width);

#endif
