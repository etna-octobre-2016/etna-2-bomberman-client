//
//  main.c
//  Bomberman_Client
//
//  Created by Steven Leclerc on 25/06/2014.
//  Copyright (c) 2014 Steven Leclerc. All rights reserved.
//

#include "init.h"
#include "socket_init.h"
#include "display.h"
#include "clean.h"
#include "events.h"

int main()
{
    init_layers();
    init_server();
    display();
    event();
  return (0);
}
