#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H

// INCLUDES
#include <stdlib.h>
#include <stdio.h>
#include "character.h"

// TYPES
typedef struct      s_player
{
  int               id;
  t_character       *character;
  struct s_player   *next;
}                   t_player;

// PROTOTYPES
t_player *player_create(int player_id);

#endif
