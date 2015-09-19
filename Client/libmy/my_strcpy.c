/*
** my_strcpy.c for my_strcpy in /home/clementcosson/C/BomberManClient/libmy
**
** Made by COSSON Clement
** Login   <cosson_c@etna-alternance.net>
**
** Started on  Fri Oct 25 09:12:23 2013 COSSON Clement
** Last update Fri Apr  3 16:49:00 2015 COSSON Clement
*/

char	*my_strcpy(char *dest, char *src)
{
  char	*ptr_tmp;

  ptr_tmp = dest;
  while (*src != '\0')
    {
      *dest = *src;
      src++;
      dest++;
    }
  *dest = '\0';
  dest = ptr_tmp;
  return (dest);
}

