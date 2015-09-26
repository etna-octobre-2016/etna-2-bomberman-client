//
//  init.h
//  BomberMan-Client
//
//  Created by Steven Leclerc on 23/09/2015.
//  Copyright (c) 2015 LynxProject. All rights reserved.
//

#ifndef BomberMan_Client_init_h
#define BomberMan_Client_init_h
#define EXIT_FAILURE 1

typedef struct Size Size;
struct Size
{
    int w;
    int h;
};
typedef struct Init Init;
struct Init
{
    void* window;
    void* wall_indestructible;
    void* wall_destructible;
    void* bomb;
    void* bomb_ignition;
    void* grass;
    void* player_one;
    void* player_two;
    void* player_three;
    void* player_four;
    void* renderer;
};

Init* init;
void init_layers();
#endif
