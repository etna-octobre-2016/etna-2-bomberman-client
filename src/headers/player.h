#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H

// INCLUDES
#include <stdlib.h>
#include <stdio.h>

// TYPES
typedef struct      s_player
{
  int               id;
  struct s_player   *next;
}                   t_player;

t_player *player_create(int player_id);

#endif
