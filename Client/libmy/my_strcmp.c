/*
** my_strcmp.c for my_strcmp in /home/clementcosson/C/BomberManClient/libmy
**
** Made by COSSON Clement
** Login   <cosson_c@etna-alternance.net>
**
** Started on  Fri Oct 25 14:41:06 2013 COSSON Clement
** Last update Fri Apr  3 16:48:31 2015 COSSON Clement
*/

int	my_strcmp(char *s1, char *s2)
{
  while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
    {
      s1++;
      s2++;
    }
  return ((int)*s1 - *s2);
}

