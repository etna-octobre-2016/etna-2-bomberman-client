/*
** my_putchar.c for my_putchar in /home/clementcosson/C/BomberManClient/libmy
**
** Made by COSSON Clement
** Login   <cosson_c@etna-alternance.net>
**
** Started on  Sat Oct 26 10:07:34 2013 COSSON Clement
** Last update Fri Apr  3 16:46:59 2015 COSSON Clement
*/
#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

