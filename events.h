//
//  events.h
//  Bomberman_Client
//
//  Created by Steven Leclerc on 23/09/2015.
//  Copyright (c) 2015 Steven Leclerc. All rights reserved.
//

#ifndef Bomberman_Client_events_h
#define Bomberman_Client_events_h
#define MAP_SIZE 144
#define SYMBOL_VOID 0
#define SYMBOL_WALL_DESTRUCTIBLE 11
#define SYMBOL_WALL_INDESTRUCTIBLE 10
#define SYMBOL_BOMB_IDLE 13
#define SYMBOL_BOMB_IGNITION 14
#define EXIT_FAILURE 1

void event();
int* map;
#endif
