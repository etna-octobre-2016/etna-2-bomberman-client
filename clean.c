//
//  clean.c
//  Bomberman_Client
//
//  Created by Steven Leclerc on 27/06/2014.
//  Copyright (c) 2014 Steven Leclerc. All rights reserved.
//

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "init.h"

void clean()
{
    SDL_DestroyRenderer(init->renderer);
    SDL_DestroyWindow(init->window);
}
