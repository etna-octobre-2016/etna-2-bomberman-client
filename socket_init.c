//
//  socket_init.c
//  Bomberman_Client
//
//  Created by Steven Leclerc on 21/09/2015.
//  Copyright (c) 2015 Steven Leclerc. All rights reserved.
//

#include "socket_init.h"
#include "./lib/my/src/headers/my.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
static s_server* server_info_create;

s_server* getSocket()
{
  return server_info_create;
}
void init_server()
{
  int                 listener;
  struct sockaddr_in  client_addr;
  struct protoent     *proto;

  if((server_info_create = malloc(sizeof(s_server))) == NULL)
  {
    my_printf("Failure\n");
    exit(EXIT_FAILURE);
  }
  if ((proto = getprotobyname("TCP")) == NULL)
  {
    exit(EXIT_FAILURE);
  }
  if ((listener = socket(AF_INET, SOCK_STREAM, proto->p_proto)) == -1)
  {
    exit(EXIT_FAILURE);
  }
  client_addr.sin_family = AF_INET;
  client_addr.sin_addr.s_addr = inet_addr("192.168.33.13");
  client_addr.sin_port = htons(4242);
  if (connect(listener, (const struct sockaddr*)&client_addr, sizeof(client_addr)) == -1)
  {
    my_printf("Server cannot be reached\n");
    exit(EXIT_FAILURE);
  }
  server_info_create->listener = listener;
}
