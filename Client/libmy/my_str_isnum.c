/*
** my_str_isnum.c for my_str_isnum in /home/clementcosson/C/BomberManClient/libmy
**
** Made by COSSON Clement
** Login   <cosson_c@etna-alternance.net>
**
** Started on  Fri Oct 25 16:44:59 2013 COSSON Clement
** Last update Fri Apr  3 16:49:25 2015 COSSON Clement
*/

int	my_str_isnum(char *str)
{
  int	var_return;
  int	i;

  var_return = 1;
  for (i = 0; str[i] != '\0'; i++)
    {
      if (!(str[i] > 47 && str[i] < 58))
	{
	  var_return = 0;
	}
    }
  return (var_return);
}

