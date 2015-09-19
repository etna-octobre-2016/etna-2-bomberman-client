/*
** my_strlen.c for my_strlen in /home/clementcosson/C/BomberManClient/libmy
**
** Made by COSSON Clement
** Login   <cosson_c@etna-alternance.net>
**
** Started on  Wed Oct 23 10:32:03 2013 COSSON Clement
** Last update Fri Apr  3 16:51:08 2015 COSSON Clement
*/
int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str)
    {
      i = 0;
      while (*str != '\0')
	{
	  i++;
	  str++;
	}
    }
  return (i);
}
