/*
** my_getnbr.c for my_getnbr in /home/clementcosson/C/BomberManClient/libmy
**
** Made by COSSON Clement
** Login   <cosson_c@etna-alternance.net>
**
** Started on  Wed Oct 23 11:05:39 2013 COSSON Clement
** Last update Fri Apr  3 16:46:38 2015 COSSON Clement
*/

#include "../headers/my.h"

int	my_getnbr(char *str)
{
  int	int_out;
  int	sign;

  int_out = 0;
  sign = 1;
  if (*str == '-')
    {
      sign = -1;
      str++;
    }
  while  (my_strlen(str) > 0 && (*str >= 48 || *str <= 57))
    {
      int_out = int_out * 10 + ((int) * str) - 48;
      str++;
    }
  return (int_out * sign);
}

