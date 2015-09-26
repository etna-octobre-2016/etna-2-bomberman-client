//
//  init.c
//  Bomberman_Client
//
//  Created by Steven Leclerc on 25/06/2014.
//  Copyright (c) 2014 Steven Leclerc. All rights reserved.
//


#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "./lib/my/src/headers/my.h"
#include "init.h"

void init_layers()
{
    //Initialisation SDL
    SDL_Window *window = NULL;
    SDL_Texture *tGrass = NULL;
    SDL_Texture *tWall_indestructible = NULL;
    SDL_Texture *tWall_destructible = NULL;
    SDL_Texture *tBomb = NULL;
    SDL_Texture *tBomb_ignition = NULL;
    SDL_Texture *tPlayer_one = NULL;
    SDL_Texture *tPlayer_two = NULL;
    SDL_Texture *tPlayer_three = NULL;
    SDL_Texture *tPlayer_four = NULL;
    SDL_Renderer *renderer = NULL;
    if((init = malloc(sizeof(init))) == NULL)
    {
      my_printf("FAILURE\n");
      exit(EXIT_FAILURE);
    }
    //Put into struct init
    init->window = window;
    init->bomb = tBomb;
    init->bomb_ignition = tBomb_ignition;
    init->grass = tGrass;
    init->player_one = tPlayer_one;
    init->player_two = tPlayer_two;
    init->player_three = tPlayer_three;
    init->player_four = tPlayer_four;
    init->wall_destructible = tWall_destructible;
    init->wall_indestructible = tWall_indestructible;
    init->renderer = renderer;
}
