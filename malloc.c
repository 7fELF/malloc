/*
** malloc.c for PSU_2016_malloc in /tekpi/PSU_2016_malloc
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
#include <stdint.h>

t_chunk *g_first_chunk = NULL;

/*
** Set all the meta of the chunk
** next is always set to NULL
*/
static void *set_chunk(void *ptr, size_t size, long free, t_chunk *prev)
{
  t_chunk *chunk;

  chunk = (t_chunk*) ptr;
  chunk->size = size;
  chunk->free = free;
  chunk->next = NULL;
  chunk->prev = prev;
  if (prev)
    prev->next = chunk;
  return ((char*) ptr) + sizeof(t_chunk) + size;
}

static t_chunk *alloc_chunk(t_chunk *chunk, size_t size) {
  t_chunk *next;
  t_chunk *leftover;
  size_t leftover_size;

  if (chunk->size <= (size + METADATA_SIZE * 2 + 8))
  {
    chunk->free = 0;
    return chunk;
  }

  next = chunk->next;
  leftover_size = chunk->size - size - (METADATA_SIZE * 2);

  leftover = (t_chunk*) set_chunk(chunk, size, 0, chunk->prev);
  chunk->next = leftover;
  set_chunk(leftover, leftover_size, 1, chunk->prev);
  leftover->next = next;
  return chunk;
}

void        *malloc(size_t size)
{
  /* write(2, "malloc-", 7); */
  size_t  size_to_add;
  t_chunk   *chunk;
  t_chunk   *last_chunk;

  size = ROUND_CHUNK_SIZE(size);
  chunk = g_first_chunk;
  last_chunk = NULL;

  while (chunk)
  {
    if (chunk->free && chunk->size >= size)
    {
      return (alloc_chunk(chunk, size) + 1);
    }
    last_chunk = chunk;
    chunk = chunk->next;
  }
  size_to_add = ROUND_HEAP_SIZE(size + METADATA_SIZE * 2 + 8);
  chunk = (t_chunk*) sbrk((intptr_t)size_to_add);
  if (chunk == (void*) -1)
    return NULL;
  last_chunk = (t_chunk*) set_chunk(chunk, size, 0, last_chunk);
  set_chunk(last_chunk, size_to_add - size - (METADATA_SIZE * 2), 1, chunk);

  if (g_first_chunk == NULL)
    g_first_chunk = chunk;

  /* write(2, "okn\n", 4); */
  return (chunk + 1);
}


/* static t_chunk     *glue_given_block(t_chunk *g) { */
/*   if (g->next && g->next->free) { */
/*     g->size += ROUND_HEAP_SIZE(g->size) + g->next->size; */
/*     g->next = g->next->next; */
/*     if (g->next) { */
/*       g->next->prev = g; */
/*     } */
/*   } */

/*   return (g); */
/* } */

