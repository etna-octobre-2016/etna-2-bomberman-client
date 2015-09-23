/*
** my_bomberman_part_2.c for Fondation in /home/clementcosson/C/BomberManClient/functions
**
** Made by COSSON Clement
** Login   <cosson_c@etna-alternance.net>
**
** Started on  Thu Jan  8 21:19:32 2015 COSSON Clement
** Last update Wed Sep 23 13:41:27 2015 COSSON Clement
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../headers/my_bomberman.h"
#include "../headers/my.h"

void     read_stdin(int socket_director, char big_table[T_MAX_TABLE])
{
  int   i;

  while (1)
    {
      for (i = 0; (big_table[i] = my_getchar ()) != '\n'; )
	i = (i < 250) ? i + 1 : i;
      if (big_table[i] == '\n')
	{
	  if (i >= 250)
	    my_putstr(CMD_IGN);
	  else if (big_table[0] == '/' && big_table[1] == 'b'
		   && big_table[2] == 'y' && big_table[3] == 'e'
		   && big_table[4] == '\n')
	    return ;
	  else if (big_table[0] != '\n')
	    chat_with_server(socket_director, big_table);
	}
      printf("reset du big table");
      reset_big_table(big_table);
      i = 0;
    }
}

void            chat_with_server(int socket_director, char *cmd)
{
  char	c;

  if (my_strcmp(cmd, "up\n") == 0)
    write(socket_director, "up", my_strlen("up"));
  else if (my_strcmp(cmd, "down\n") == 0)
    write(socket_director, "down", my_strlen("down"));
  else if (my_strcmp(cmd, "left\n") == 0)
    write(socket_director, "left", my_strlen("left"));
  else if (my_strcmp(cmd, "right\n") == 0)
    write(socket_director, "right", my_strlen("right"));
  else if (my_strcmp(cmd, "bomb\n") == 0)
    write(socket_director, "bomb", my_strlen("bomb"));
  else if (my_strcmp(cmd, "update\n") == 0)
    {
      write(socket_director, "update", my_strlen("update"));
      give_me_the_map(socket_director);
      return ;
    }
  else
    return ;
  while ((c = my_getsocketchar(socket_director)) != '\0')
      my_putchar(c);
  my_putstr("\n");
}

void	reset_big_table(char big_table[T_MAX_TABLE])
{
  int   i;

  for (i = 0; i < T_MAX_TABLE; i++)
    big_table[i] = '\0';
}

int	connect_to_server(t_args *s_as)
{
  int			co;
  struct sockaddr_in	server;

  if (s_as->v_ip == 4)
    {
      s_as->d_socket = socket(AF_INET , SOCK_STREAM , 0);
      if (s_as->d_socket == -1)
	{
	  my_putstr(CANT_NOT_CREATE_SOCK);
	  return (0);
	}
      server.sin_addr.s_addr = inet_addr(s_as->ip);
      server.sin_family = AF_INET;
      server.sin_port = htons(s_as->port);
      co = connect(s_as->d_socket, (struct sockaddr *)&server, sizeof(server));
      puts((co < 0) ? CON_KO : CON_OK );
      return ((co < 0) ? 0 : 1);
    }
  else if (s_as->v_ip == 6)
    my_putstr(IP_V6_NOT_IMPL);
  return (0);
}

char    my_getsocketchar(int socket_director)
{
  char  c;

  if (read(socket_director, &c, 1))
    return c;
  else
    return EOF;
}
