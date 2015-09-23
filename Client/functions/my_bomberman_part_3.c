/*
** my_bomberman_part_3.c for bomberman in /Users/clementcosson/Projets/C/BomberMan
**
** Made by COSSON Clement
** Login   <cosson_c@etna-alternance.net>
**
** Started on  Wed Sep 23 12:14:43 2015 COSSON Clement
** Last update Wed Sep 23 13:51:55 2015 COSSON Clement
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../headers/my_bomberman.h"
#include "../headers/my.h"

void    give_me_the_map(int socket_director)
{
  char	c;

  printf("give me the fucking map\n");
  while ((c = my_getsocketchar(socket_director)) != '\0')
    my_putchar(c);
  my_putchar('\n');
}
