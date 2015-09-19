/*
** my_getchar.c for my_getchar in /home/clementcosson/C/BomberManClient/libmy
**
** Made by COSSON Clement
** Login   <cosson_c@etna-alternance.net>
**
** Started on  Sat Jan 10 20:54:11 2015 COSSON Clement
** Last update Fri Apr  3 16:46:08 2015 COSSON Clement
*/
#include <stdio.h>
#include <unistd.h>

char    my_getchar()
{
  char  c;

  if (read(STDIN_FILENO, &c, 1))
    return c;
  else
    return EOF;
}
