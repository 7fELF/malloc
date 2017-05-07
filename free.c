#include "private.h"

static int addr_is_valid(t_chunk *chunk)
{
  return (g_chunks
      && chunk && chunk > g_chunks
      && (void*) chunk < sbrk(0));
}

static void merge_free_blocks(t_chunk *g)
{
  if (g->prev && g->prev->free)
  {
    g->prev->size += g->size + T_CHUNK_SIZE;
    g->prev->next = g->next;
    if (g->next)
      g->next->prev = g->prev;
    PREV(g);
  }
  if (g->next && g->next->free)
  {
    g->size += g->next->size + T_CHUNK_SIZE;
    g->next = g->next->next;
    if (g->next)
      g->next->prev = g;
  }
  if (g->next == NULL && g->size >= PAGESIZE)
  {
    if (g->prev)
      g->prev->next = NULL;
    else
      g_chunks = NULL;
    brk(g);
  }
}

void        free(void *ptr)
{
  t_chunk   *chunk;

  chunk = GET_CHUNK_FROM_DATA_PTR(ptr);
  if (addr_is_valid(chunk))
  {
    chunk->free = 1;
    merge_free_blocks(chunk);
  }
}
