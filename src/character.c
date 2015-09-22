#include "headers/main.h"
#include "headers/character.h"

t_character   *character_create()
{
  t_character *character;

  character = malloc(sizeof(t_character));
  if (character == NULL)
  {
    return (NULL);
  }
  character->backward = &character_move_backward;
  character->forward = &character_move_forward;
  character->left = &character_move_left;
  character->right = &character_move_right;
  character->throwBomb = &character_throw_bomb;
  return (character);
}
void character_move_backward(t_character *character)
{
  UNUSED(character);
  printf("en arriere\n");
}
void character_move_forward(t_character *character)
{
  UNUSED(character);
  printf("en avant\n");
}
void character_move_left(t_character *character)
{
  UNUSED(character);
  printf("a gauche\n");
}
void character_move_right(t_character *character)
{
  UNUSED(character);
  printf("a droite\n");
}
void character_throw_bomb(t_character *character)
{
  UNUSED(character);
  printf("throwing bomb\n");
}
