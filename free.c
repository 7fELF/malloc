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

static t_chunk *addr_is_valid(void *ptr) {
  t_chunk      *tmp;

  tmp = ptr;
  if (g_first_chunk) {
    if (tmp > g_first_chunk && ptr < sbrk(0)) {
      return ptr;
    }
  }

  return (NULL);
}

static void    glue_given_block(t_chunk *g) {
  if (g->prev && g->prev->free) {
    g->prev->size += METADATA_SIZE + g->size;
    g->prev->next = g->prev;
    g = g->prev;
  }
  if (g->next && g->next->free) {
    g->size += METADATA_SIZE + g->next->size;
    g->next = g->next->next;
    if (g->next) {
      g->next->prev = g;
    }
  } else {
    if (g->prev) {
      g->prev->next = NULL;
    } else
        g_first_chunk = NULL;
    brk(0);
  }
}

void        free(void *ptr)
{
  t_chunk   *tmp;

  if (addr_is_valid(ptr) && ptr) {
    tmp = addr_is_valid((t_chunk *)ptr);
    tmp -= 1;
    tmp->free = 1;
    glue_given_block(tmp);
  }
}
