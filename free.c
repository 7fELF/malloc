/*
** free.c for PSU_2016_malloc in /Users/pichar_v/Documents/tek2/PSU_2016_malloc
**
** Made by Valentin Pichard
** Login   <valentin.pichard@epitech.eu>
**
** Started on  Fri Jan 27 15:07:09 2017 Solomon Hykes
** Last update Fri Jan 27 15:07:09 2017 Solomon Hykes
*/

#include "malloc.h"

static int addr_is_valid(t_chunk *chunk) {
  return (g_first_chunk && chunk
      && chunk > g_first_chunk && (void*) chunk < sbrk(0));
}

static void merge_free_blocks(t_chunk *g) {
  if (g->prev && g->prev->free) {
    g->prev->size += g->size + METADATA_SIZE;
    g->prev->next = g->next;
    g->next->prev = g->prev;
    g = g->prev;
  }
  if (g->next && g->next->free) {
    g->size += g->next->size + METADATA_SIZE;
    g->next = g->next->next;
    if (g->next) {
      g->next->prev = g;
    }
  }
  /* if (g->next == NULL){ */
  /*   g->prev->next = NULL; */
  /*   brk(g); */
  /* } */
}


#include <stdio.h>
void        free(void *ptr)
{
  t_chunk   *tmp;

  tmp = (t_chunk *) ptr;
  if (addr_is_valid(tmp)) {
    t_chunk *chunk = g_first_chunk;
    t_chunk *to_find = tmp - 1;
    while (chunk)
    {
      if (chunk == to_find)
      {
        tmp = tmp - 1;
        tmp->free = 1;
        merge_free_blocks(tmp);
        return;
      }
      chunk = chunk->next;
    }
    fprintf(stderr, "bad free: %p\n", ptr);
  }
}
