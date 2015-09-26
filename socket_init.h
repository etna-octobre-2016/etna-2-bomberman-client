//
//  socket_init.h
//  Bomberman_Client
//
//  Created by Steven Leclerc on 21/09/2015.
//  Copyright (c) 2015 Steven Leclerc. All rights reserved.
//

#ifndef __Bomberman_Client__socket_init__
#define __Bomberman_Client__socket_init__
#define EXIT_FAILURE 1

typedef struct            s_server
{
    int               listener;
}                     s_server;

s_server* getSocket();
void init_server();
#endif
