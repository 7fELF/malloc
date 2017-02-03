/*
** realloc.c for PSU_2016_malloc in /tekpi/PSU_2016_malloc
**
** Made by Valentin Pichard
** Login   <valentin.pichard@epitech.eu>
**
** Started on  Fri Jan 27 15:07:09 2017 Solomon Hykes
** Last update Fri Jan 27 15:07:09 2017 Solomon Hykes
*/

#include "private.h"
#include <string.h>

/*
 * TODO: check if we can expend without moving the memory
 */
void *realloc(void *ptr, size_t size)
{
  t_chunk *chunk;

  if (ptr == NULL)
    return (malloc(size));
  chunk = (t_chunk*)ptr - 1;
  if (size == chunk->size)
    return ptr;

  void *new = malloc(size);
  if(new == NULL)
    return NULL;

  if (size < chunk->size)
    memcpy(new, ptr, size);
  else
    memcpy(new, ptr, chunk->size);
  free(ptr);
  return (new);
}
