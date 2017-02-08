/*
** calloc.c for PSU_2016_malloc in /Users/pichar_v/Documents/tek2/PSU_2016
**
** Made by Valentin Pichard
** Login   <valentin.pichard@epitech.eu>
**
** Started on  Fri Jan 27 15:07:09 2017 Solomon Hykes
** Last update Fri Jan 27 15:07:09 2017 Solomon Hykes
*/

#include <string.h>
#include "private.h"

void *calloc(size_t count, size_t size)
{
  void *ptr;

  ptr = malloc(count * size);
  if (ptr)
    memset(ptr, 0, count * size);
  return (ptr);
}
