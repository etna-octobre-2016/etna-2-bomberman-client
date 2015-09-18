#ifndef BOMBERMAN_GAME_H
#define BOMBERMAN_GAME_H

// INCLUDES
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "map.h"

// TYPES
typedef struct  s_game
{
  t_map         *map;
  void          (*quit)();
  void          (*start)();
}               t_game;

// PROTOTYPES
t_game *game_init();
void   game_quit();
void   game_start();

#endif
