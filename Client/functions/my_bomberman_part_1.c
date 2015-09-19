/*
** my_bomberman_part_1.c for Fondation in /home/clementcosson/C/BomberManClient/functions
**
** Made by COSSON Clement
** Login   <cosson_c@etna-alternance.net>
**
** Started on  Thu Jan  8 21:19:32 2015 COSSON Clement
** Last update Fri Apr  3 16:40:10 2015 COSSON Clement
*/
#include <stdio.h>
#include "../headers/my_bomberman.h"
#include "../headers/my.h"

void    print_usage()
{
  my_putstr("usage: ./bomberman --ip [enter_an_ip] --port [enter_a_port]\n");
}

int     check_if_params_are_corrects(int ac, char **av, t_args *s_as)
{
  if (ac != 5)
    return (0);
  if (my_strcmp(av[1], "--ip") == 0 && my_strcmp(av[3], "--port") == 0)
    {
      if (((s_as->port = (unsigned short) check_if_port_is_correct(av[4])) != 0)
	  && check_if_ip_is_correct(check_if_look_ip(av[2], s_as), av[2], 0, 0))
	{
	  my_strcpy(s_as->ip, av[2]);
	  return (1);
	}
    }
  else if (my_strcmp(av[1], "--port") == 0 && my_strcmp(av[3], "--ip") == 0)
    if (((s_as->port = (unsigned short) check_if_port_is_correct(av[2])) != 0)
	&& check_if_ip_is_correct(check_if_look_ip(av[4], s_as), av[4], 0, 0))
      {
	my_strcpy(s_as->ip, av[4]);
	return (1);
      }
  return (0);
}

int     check_if_look_ip(char *str, t_args *s_as)
{
  int	i;
  int	cmpt_dot;
  int	cmpt_colon;

  cmpt_dot = 0;
  cmpt_colon = 0;
  for (i = 0; i < my_strlen(str); i++)
  {
    if (str[i] == '.')
      cmpt_dot++;
    else if (str[i] == ':')
      cmpt_colon++;
  }
  if (cmpt_dot == 3 && cmpt_colon == 0)
     s_as->v_ip = 4;
  else if (cmpt_colon == 7 && cmpt_dot == 0)
    s_as->v_ip = 6;
  else
    s_as->v_ip = 0;
  return (s_as->v_ip);
}

int     check_if_ip_is_correct(int v_ip, char *str, int i, int index)
{
  if (v_ip == 4 || v_ip == 6)
    for (; i < my_strlen(str); i++)
      if ((index > 3 && v_ip == 4) || (index > 4))
	return (0);
      else
	if (str[i] == ((v_ip == 4) ? '.' : ':'))
	  {
	    if (index == 0)
	      return (0);
	    else
	      index = 0;
	  }
	else
	  {
	    index++;
	    if (v_ip == 4 && !(str[i] >= '\x30' && str[i] <= '\x39'))
	      return (0);
	    else if (v_ip == 6 && !((str[i] >= '\x30' && str[i] <= '\x39')
				|| (str[i] >= '\x41' && str[i] <= '\x46')
				|| (str[i] >= '\x61' && str[i] <= '\x66')))
	      return (0);
	  }
  else
    return (0);
  return (1);
}

int     check_if_port_is_correct(char *port)
{
  int	nbr;

  if (my_str_isnum(port))
    {
      nbr = my_getnbr(port);
      if (nbr >= PORT_MIN && nbr <= PORT_MAX)
	return (nbr);
    }
  return (0);
}

