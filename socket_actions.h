//
//  socket_actions.h
//  Bomberman_Client
//
//  Created by Steven Leclerc on 22/09/2015.
//  Copyright (c) 2015 Steven Leclerc. All rights reserved.
//

#ifndef __Bomberman_Client__socket_actions__
#define __Bomberman_Client__socket_actions__
#define EXIT_FAILURE 1

void right_action();
void left_action();
void up_action();
void down_action();
void bomb_action();
void update_action();
void convertCharInt(char* map_char);
#endif
