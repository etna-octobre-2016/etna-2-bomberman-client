//
//  Events.c
//  Bomberman_Client
//
//  Created by Steven Leclerc on 27/06/2014.
//  Copyright (c) 2014 Steven Leclerc. All rights reserved.
//

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <math.h>
#include <unistd.h>
#include "./lib/my/src/headers/my.h"
#include "clean.h"
#include "socket_init.h"
#include "socket_actions.h"
#include "events.h"
#include "init.h"


void event()
{
  int u;
  int i;
  int x;
  int y;
  char *start;
  SDL_Event event;
  unsigned int elapsed;
  unsigned int lasttime;
  SDL_Rect Pos[MAP_SIZE];
  int quit = 0;
  s_server* server_info_create;

  map = NULL;
  server_info_create = getSocket();
  if ((start = malloc(sizeof(char) * 5)) == NULL)
  {
    my_printf("FAILURE\n");
    exit(EXIT_FAILURE);
  }
  u = sqrt(MAP_SIZE);
  read(server_info_create->listener, start, sizeof(char) * 5);
  if (my_strcmp(start, "start") == 0)
  {
    while (SDL_PollEvent(&event) || quit != 1)
    {
      SDL_RenderClear(init->renderer);
      update_action();
      for (i = 0, x = 0, y = 0; i < MAP_SIZE; i++, y += 16)
      {
        if (i == u)
        {
          y = 0;
          x += 16;
          u += 12;
        }
        Pos[i].x = x;
        Pos[i].y = y;
        Pos[i].w = 16;
        Pos[i].h = 16;
        if (map[i] == 0)
        {
          SDL_RenderCopy(init->renderer, init->grass, NULL, &Pos[i]);
        }
        else if (map[i] == 10)
        {
          SDL_RenderCopy(init->renderer, init->wall_indestructible, NULL, &Pos[i]);
        }
        else if (map[i] == 11)
        {
          SDL_RenderCopy(init->renderer, init->wall_destructible, NULL, &Pos[i]);
        }
        else if (map[i] == 13 || map[i] == 3 || map[i] == 5 || map[i] == 7 || map[i] == 9)
        {
          SDL_RenderCopy(init->renderer, init->bomb, NULL, &Pos[i]);
        }
        else if (map[i] == 14)
        {
          SDL_RenderCopy(init->renderer, init->bomb_ignition, NULL, &Pos[i]);
        }
        else if (map[i] == 2)
        {
          SDL_RenderCopy(init->renderer, init->player_one, NULL, &Pos[i]);
        }
        else if (map[i] == 4)
        {
          SDL_RenderCopy(init->renderer, init->player_two, NULL, &Pos[i]);
        }
        else if (map[i] == 6)
        {
          SDL_RenderCopy(init->renderer, init->player_three, NULL, &Pos[i]);
        }
        else if (map[i] == 8)
        {
          SDL_RenderCopy(init->renderer, init->player_four, NULL, &Pos[i]);
        }
      }
      lasttime = SDL_GetTicks();
      SDL_RenderPresent(init->renderer);
      u = sqrt(MAP_SIZE);
      switch (event.type)
      {
        case SDL_KEYDOWN:
          switch (event.key.keysym.sym)
          {
            case SDLK_RIGHT:
              right_action();
              break;
            case SDLK_LEFT:
              left_action();
              break;
            case SDLK_DOWN:
              down_action();
              break;
            case SDLK_UP:
              up_action();
              break;
            case SDLK_SPACE:
              bomb_action();
              break;
            case SDLK_ESCAPE:
              quit = 1;
              break;
          }
        default:
          break;
      }
      /*Gestion de la latence à 40millisecondes*/
      elapsed = SDL_GetTicks()-lasttime;
      if (elapsed<20)
      {
        SDL_Delay(40-elapsed);
      }
    }
  }
}
