//
//  display.c
//  Bomberman_Client
//
//  Created by Steven Leclerc on 26/06/2014.
//  Copyright (c) 2014 Steven Leclerc. All rights reserved.
//


#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "lib/my/src/headers/my.h"
#include <unistd.h>
#include "init.h"

void display()
{
    Size *size;
    char cwd[1024];

    getcwd(cwd, sizeof(cwd));
    if((size = malloc(sizeof(size))) == NULL)
    {
      my_printf("FAILURE\n");
      exit(EXIT_FAILURE);
    }
    size->w = 192;
    size->h = 192;
    SDL_Init(SDL_INIT_VIDEO);
    init->window = SDL_CreateWindow("BomberMan", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size->w, size->h, SDL_WINDOW_SHOWN);
    init->renderer = SDL_CreateRenderer(init->window, -1, SDL_RENDERER_ACCELERATED);
    init->bomb = IMG_LoadTexture(init->renderer, my_strconcat(cwd, "/Img/bomb.png"));
    init->bomb_ignition = IMG_LoadTexture(init->renderer, my_strconcat(cwd,"/Img/bomb_ignition.png"));
    init->grass = IMG_LoadTexture(init->renderer, my_strconcat(cwd,"/Img/grass.png"));
    init->player_one = IMG_LoadTexture(init->renderer, my_strconcat(cwd,"/Img/player_1.png"));
    init->player_two = IMG_LoadTexture(init->renderer, my_strconcat(cwd,"/Img/player_2.png"));
    init->player_three = IMG_LoadTexture(init->renderer, my_strconcat(cwd,"/Img/player_3.png"));
    init->player_four = IMG_LoadTexture(init->renderer, my_strconcat(cwd,"/Img/player_4.png"));
    init->wall_destructible = IMG_LoadTexture(init->renderer, my_strconcat(cwd,"/Img/wall_destructible.png"));
    init->wall_indestructible = IMG_LoadTexture(init->renderer, my_strconcat(cwd,"/Img/wall_indestructible.png"));
}
