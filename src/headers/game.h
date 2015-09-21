#ifndef BOMBERMAN_GAME_H
#define BOMBERMAN_GAME_H

// INCLUDES
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "map.h"
#include "player.h"
#include "window.h"

// TYPES
typedef struct  s_game
{
  t_map         *map;
  t_player      *players;
  t_window      *window;
  bool          is_running;

  t_player      *(*getPlayerById)(int player_id);
  bool          (*addPlayer)(int player_id);
  void          (*destroy)();
  void          (*quit)();
  void          (*start)();
}               t_game;

// PROTOTYPES
t_game      *game_get_data();
t_game      *game_init();
t_player    *game_get_player_by_id(int player_int);
bool        game_add_player(int player_id);
void        game_destroy();
void        game_quit();
void        game_start();

#endif
