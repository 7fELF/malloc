/*
** realloc.c for PSU_2016_malloc in /tekpi/PSU_2016_malloc
**
** Made by Valentin Pichard
** Login   <valentin.pichard@epitech.eu>
**
** Started on  Fri Jan 27 15:07:09 2017 Solomon Hykes
** Last update Fri Jan 27 15:07:09 2017 Solomon Hykes
*/

#include "malloc.h"

void *realloc(void *ptr, size_t size)
{
  write(2, "realloc\n", 8);
  (void) size;
  (void) ptr;
  return (NULL);
}
