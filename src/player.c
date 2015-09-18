#include "headers/player.h"

t_player *player_create(int player_id)
{
  t_player *player;

  player = malloc(sizeof(t_player));
  if (player == NULL)
  {
    return (NULL);
  }
  player->id = player_id;
  player->next = NULL;
  return (player);
}
