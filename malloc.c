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

static void *set_chunk(void *ptr, size_t size, long free, t_chunk *prev)
{
  t_chunk *chunk;

  chunk = (t_chunk*) ptr;
  chunk->size = size;
  chunk->free = free;
  chunk->next = prev ? prev->next : NULL;
  if (prev)
  {
    chunk->next = prev->next;
    prev->next = chunk;
  }
  else
  {
    chunk->next = NULL;
  }
  chunk->prev = prev;
  return ((char*) ptr) + sizeof(t_chunk) + size;
}

static t_chunk     *get_last_block(void) {
  t_chunk   *tmp;

  tmp = g_first_chunk;
  while (tmp->next)
    tmp = tmp->next;

  return (tmp);
}

void        *malloc(size_t size)
{
  write(2, "malloc-", 7);
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
      if (chunk->size <= (size + METADATA_SIZE + 8))
      {
        size = chunk->size;
      }
      else
      {
        //split
      }
      chunk->free = 0;
      return (chunk + 1);
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

  write(2, "ok\n", 3);
  return (chunk + 1);
}

static void        split_block(t_chunk *chunk, size_t size) {
  /*
   * To recode using set_chunk
   * if the chunk is too small to make two parts, keep the chunk intact
   */
}

static t_chunk     *glue_given_block(t_chunk *g) {
  if (g->next && g->next->free) {
    g->size += ROUND_HEAP_SIZE(g->size) + g->next->size;
    g->next = g->next->next;
    if (g->next) {
      g->next->prev = g;
    }
  }

  return (g);
}

