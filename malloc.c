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

#include <time.h>

t_chunk *g_first_chunk = NULL;

/*
** Set all the meta of the chunk
** next is always set to NULL
*/
static void *set_chunk(void *ptr, t_chunk chunk_data)
{
  t_chunk *chunk;

  chunk = (t_chunk*) ptr;
  chunk->size = chunk_data.size;
  chunk->free = chunk_data.free;
  chunk->prev = chunk_data.prev;
  chunk->next = chunk_data.next;
  if (chunk->prev)
    chunk->prev->next = chunk;
  if (chunk->next)
    chunk->next->prev = chunk;
  return ((char*) ptr) + sizeof(t_chunk) + chunk->size;
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

  chunk->size = size;
  chunk->free = 0;
  leftover = (t_chunk*) (((char*)(chunk + 1)) + size);
  chunk->next = leftover;

  set_chunk(leftover, (t_chunk){ leftover_size, 1, chunk, next });

  return chunk;
}

void        *malloc(size_t size)
{
  size_t  size_to_add;
  t_chunk   *chunk;
  t_chunk   *last_chunk;

  size = ROUND_CHUNK_SIZE(size);
  chunk = g_first_chunk;
  last_chunk = NULL;
  while (chunk)
  {
    if (chunk->free && chunk->size >= size)
      return (alloc_chunk(chunk, size) + 1);
    last_chunk = chunk;
    chunk = chunk->next;
  }
  size_to_add = ROUND_HEAP_SIZE(size + METADATA_SIZE * 2 + 8);
  chunk = (t_chunk*) sbrk((intptr_t)size_to_add);
  if (chunk == (void*) -1)
    return NULL;

  last_chunk = (t_chunk*) set_chunk(chunk, ((t_chunk){ size, 0, last_chunk, NULL }));
  set_chunk(last_chunk,
      ((t_chunk) { size_to_add - size - (METADATA_SIZE * 2), 1, chunk, NULL}));

  if (g_first_chunk == NULL)
    g_first_chunk = chunk;
  return (chunk + 1);
}

