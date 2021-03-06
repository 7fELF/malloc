#include <stdint.h>
#include "private.h"

t_chunk *g_chunks = NULL;

static void        *set_chunk(void *ptr, t_chunk chunk_data)
{
  t_chunk          *chunk;

  chunk = (t_chunk*) ptr;
  chunk->size = chunk_data.size;
  chunk->free = chunk_data.free;
  chunk->prev = chunk_data.prev;
  chunk->next = chunk_data.next;
  if (chunk->prev)
    chunk->prev->next = chunk;
  if (chunk->next)
    chunk->next->prev = chunk;
  return (CHUNK_END_PTR(chunk));
}

static t_chunk     *alloc_chunk(t_chunk *chunk, size_t size)
{
  t_chunk          *next;
  t_chunk          *leftover;
  size_t           leftover_size;

  if (chunk->size <= (size + T_CHUNK_SIZE * 2 + 8))
  {
    chunk->free = 0;
    return (chunk);
  }
  next = chunk->next;
  leftover_size = chunk->size - size - (T_CHUNK_SIZE * 2);
  chunk->size = size;
  chunk->free = 0;
  leftover = (t_chunk *)(((char*)(chunk + 1)) + size);
  chunk->next = leftover;
  set_chunk(leftover, (t_chunk){ leftover_size, 1, chunk, next });
  return (chunk);
}

static t_chunk     *alloc_new_chunk(size_t size, t_chunk *last_chunk)
{
  size_t           size_to_add;
  t_chunk          *chunk;

  size_to_add = ROUND_TO_PAGESIZE(size + T_CHUNK_SIZE * 2 + 8);
  chunk = (t_chunk*) sbrk((intptr_t)size_to_add);
  if (chunk == (void*) -1)
    return (NULL);
  last_chunk = (t_chunk*) set_chunk(chunk,
      (t_chunk) { size, 0, last_chunk, NULL });
  set_chunk(last_chunk,
      (t_chunk) { (size_to_add - size - (T_CHUNK_SIZE * 2)), 1, chunk, NULL });
  if (g_chunks == NULL)
    g_chunks = chunk;
  return ((t_chunk*) CHUNK_DATA(chunk));
}

void               *malloc(size_t size)
{
  t_chunk          *chunk;
  t_chunk          *last_chunk;

  if (size == 0 || (intptr_t) size < 0)
  {
    return (NULL);
  }
  size = ROUND_TO_WORD(size);
  chunk = g_chunks;
  last_chunk = NULL;
  while (chunk)
  {
    if (chunk->free && chunk->size >= size)
      return (CHUNK_DATA(alloc_chunk(chunk, size)));
    last_chunk = chunk;
    NEXT(chunk);
  }
  return (alloc_new_chunk(size, last_chunk));
}
