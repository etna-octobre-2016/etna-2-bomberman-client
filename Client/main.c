/*
** main.c for Bomberman in /home/clementcosson/C/BomberManClient
**
** Made by COSSON Clement
** Login   <cosson_c@etna-alternance.net>
**
** Started on  Thu Jan  8 14:44:19 2015 COSSON Clement
** Last update Fri Apr  3 16:55:39 2015 COSSON Clement
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "headers/my_bomberman.h"
#include "headers/my.h"

int	main(int argc, char *argv[])
{
  char		big_table[T_MAX_TABLE];
  t_args	*s_args;

  reset_big_table(big_table);
  if ((s_args = malloc(sizeof(t_args))) == NULL)
    return (0);
  if (check_if_params_are_corrects(argc, argv, s_args))
    {
      if (connect_to_server(s_args))
	{
	  read_stdin(s_args->d_socket, big_table);
	  close(s_args->d_socket);
	}
    }
  else
    print_usage();
  free(s_args);
  return (0);
}

