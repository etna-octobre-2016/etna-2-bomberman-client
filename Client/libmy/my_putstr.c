/*
** my_putstr.c for my_putstr in /home/clementcosson/C/BomberManClient/libmy
**
** Made by COSSON Clement
** Login   <cosson_c@etna-alternance.net>
**
** Started on  Wed Oct 23 10:12:52 2013 COSSON Clement
** Last update Fri Apr  3 16:47:25 2015 COSSON Clement
*/

void    my_putchar(char c);

int	my_putstr(char *str)
{
  if (str)
    {
      while (*str != '\0')
	{
	  my_putchar(*str);
	  str++;
	}
    }
  return (0);
}
