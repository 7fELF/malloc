#include "private.h"
#include <string.h>

/*
** TODO: check if we can expend without moving the memory
*/
void         *realloc(void *ptr, size_t size)
{
  t_chunk    *chunk;
  void       *new;

  if (ptr == NULL)
    return (malloc(size));
  chunk = GET_CHUNK_FROM_DATA_PTR(ptr);
  if (size == chunk->size)
    return (ptr);
  new = malloc(size);
  if (new == NULL)
    return (NULL);
  if (size < chunk->size)
    memcpy(new, ptr, size);
  else
    memcpy(new, ptr, chunk->size);
  free(ptr);
  return (new);
}
