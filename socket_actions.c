//
//  socket_actions.c
//  Bomberman_Client
//
//  Created by Steven Leclerc on 22/09/2015.
//  Copyright (c) 2015 Steven Leclerc. All rights reserved.
//

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "./lib/my/src/headers/my.h"
#include "events.h"
#include "my_strcharconcat.h"
#include "socket_actions.h"
#include "socket_init.h"

void right_action()
{
    char* char_return;
    s_server* server_info_create;

    char_return = NULL;
    server_info_create = getSocket();
    write(server_info_create->listener, "right", sizeof("right"));
}
void left_action()
{
    char* char_return;
    s_server* server_info_create;

    char_return = NULL;
    server_info_create = getSocket();
    write(server_info_create->listener, "left", sizeof("left"));
}
void up_action()
{
    char* char_return;
    s_server* server_info_create;

    char_return = NULL;
    server_info_create = getSocket();
    write(server_info_create->listener, "up", sizeof("up"));
}
void down_action()
{
    char* char_return;
    s_server* server_info_create;

    char_return = NULL;
    server_info_create = getSocket();
    write(server_info_create->listener, "down", sizeof("down"));
}
void bomb_action()
{
    char* char_return;
    s_server* server_info_create;

    char_return = NULL;
    server_info_create = getSocket();
    write(server_info_create->listener, "bomb", sizeof("bomb"));
}
void update_action()
{
    char* char_return;
    int return_read;
    s_server* server_info_create;

    server_info_create = getSocket();
    if ((char_return = malloc(sizeof(char)*400)) == NULL)
    {
        my_printf("FAILURE\n");
        exit(EXIT_FAILURE);
    }
    write(server_info_create->listener, "update", sizeof("update"));
    return_read = read(server_info_create->listener, char_return, 400);
    convertCharInt(char_return);
}

void convertCharInt(char* map_char)
{
  int i_one;
  int nb_args;
  //COUNT NB_ARGS
  for (i_one = 1; map_char[i_one] == ' '; i_one++);
  for (nb_args = 1; map_char[i_one] != '\0'; i_one++)
  {
    if (map_char[i_one] == ' ')
    {
      if (map_char[i_one + 1] != ' ' && map_char[i_one + 1] != '\0')
      {
        nb_args++;
      }
    }
  }
  // my_printf("nb_args = %d", nb_args);
  /* FIRST MALLOC IF MAP == NULL */
  if (map == NULL)
  {
    if((map = malloc((nb_args) * sizeof(int))) == NULL)
    {
      my_printf("FAILURE\n");
      exit(EXIT_FAILURE);
    }
  }
  /*SKIM ALL CHAR AND FULFIL MAP*/
  for (i_one = 1; map_char[i_one] == ' '; i_one++);
  for (nb_args = 0; map_char[i_one] != '\0'; i_one++)
  {
    if (map_char[i_one] != ' ')
    {
      if (map_char[i_one + 1] != ' ' && map_char[i_one + 1] != '\0')
      {
        map[nb_args] = 10 + (map_char[i_one + 1] - 48);
        i_one++;
        nb_args++;
      }
      else
      {
        map[nb_args] = map_char[i_one] - 48;
        nb_args++;
      }
    }
  }
  free(map_char);
}
