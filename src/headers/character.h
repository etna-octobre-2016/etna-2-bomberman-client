#ifndef BOMBERMAN_CHARACTER_H
#define BOMBERMAN_CHARACTER_H

// INCLUDES
#include <stdlib.h>
#include <stdio.h>

// TYPES
typedef struct  s_character
{
  void          (*backward)(struct s_character *character);
  void          (*forward)(struct s_character *character);
  void          (*left)(struct s_character *character);
  void          (*right)(struct s_character *character);
  void          (*throwBomb)(struct s_character *character);
}               t_character;

// PROTOTYPES
t_character   *character_create();
void          character_move_backward(t_character *character);
void          character_move_forward(t_character *character);
void          character_move_left(t_character *character);
void          character_move_right(t_character *character);
void          character_throw_bomb(t_character *character);

#endif
