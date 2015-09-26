/*
** my_strcpy.c for  in /Users/stevenleclerc/Documents/Prog-C/Piscine5/lecler_s/my_strcpy
**
** Made by LECLERC Steven
** Login   <lecler_s@etna-alternance.net>
**
** Started on  Fri Oct 25 09:06:06 2013 LECLERC Steven
** Last update Fri Oct 25 11:51:52 2013 LECLERC Steven
*/
#include <stdlib.h>

char *my_strcharconcat(char first_char, char second_char)
{
  char* final_string;

  if ((final_string = malloc(sizeof(char) * 2)) == NULL)
  {
    exit(1);
  }
    final_string[0] = first_char;
    final_string[1] = second_char;
  return (final_string);
}
