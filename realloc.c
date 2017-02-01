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
#include <string.h>

#include <stdio.h>

/*
 * change that
 */
void *realloc(void *ptr, size_t size)
{
  t_chunk *chunk;

  void *new = malloc(size);
  if(new == NULL)
    return NULL;
  if (ptr == NULL)
    return new;
  chunk = (t_chunk*)ptr - 1;
  if (size < chunk->size) {
    return ptr;
  }
  memcpy(new, ptr, chunk->size);
  free(ptr);
  return (new);
}
