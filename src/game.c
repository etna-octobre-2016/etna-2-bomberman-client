#include "headers/game.h"

static t_game *g_game;

t_game *game_get_data()
{
  return (g_game);
}
t_game *game_init()
{
  g_game = malloc(sizeof(t_game));
  if (g_game == NULL)
  {
    return (NULL);
  }
  g_game->map = map_init();
  g_game->window = window_init();
  g_game->players = NULL;
  g_game->addPlayer = &game_add_player;
  g_game->getPlayerById = &game_get_player_by_id;
  g_game->quit = &game_quit;
  g_game->start = &game_start;
  if (g_game->map == NULL || g_game->window == NULL)
  {
    return (NULL);
  }
  return (g_game);

}
t_player *game_get_player_by_id(int player_id)
{
  t_player *player;

  player = g_game->players;
  while (player != NULL)
  {
    if (player->id == player_id)
    {
      return (player);
    }
    player = player->next;
  }
  return (NULL);
}
bool game_add_player(int player_id)
{
  t_player *tmp;
  t_player *player;

  player = player_create(player_id);
  if (player == NULL)
  {
    return (false);
  }
  if (g_game->players == NULL)
  {
    g_game->players = player;
    return (true);
  }
  tmp = g_game->players;
  while (tmp->next != NULL)
  {
    tmp = tmp->next;
  }
  tmp->next = player;
  return (true);
}
void game_quit()
{
  // g_game->map->destroy(); // TODO: fix segfault
  free(g_game);
  printf("game quit\n");
}
void game_start()
{
  printf("game started\n");
}
