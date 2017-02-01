/*
** malloc.c for PSU_2016_malloc in /Users/pichar_v/Documents/tek2/PSU_2016_malloc
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

t_chunk *g_first_chunk = NULL;

t_chunk     *get_free_block(size_t size) {
  t_chunk   *tmp;

  tmp = g_first_chunk;
  while (tmp && (tmp->free && 
  ROUND_HEAP_SIZE(tmp->size) >= ROUND_HEAP_SIZE(size))) {
    tmp = tmp->next;
  }

  return (tmp);
}

t_chunk     *get_last_block(void) {
  t_chunk   *tmp;

  tmp = g_first_chunk;
  while (tmp->next)
    tmp = tmp->next;

  return (tmp);
}

t_chunk     *extend_local_heap(size_t size) {
  t_chunk   *tmp;

  tmp = sbrk(0);
  if (sbrk(ROUND_HEAP_SIZE(size)) == (void*)-1)
    return (NULL);
  tmp->size = size;
  tmp->next = NULL;
  tmp->prev = get_last_block();
  if (get_last_block()) {
    get_last_block()->next = tmp;
  }
  tmp->free = 0;

  return (tmp);
}

void        split_given_block(t_chunk *g, size_t size) {
  t_chunk *tmp;

  tmp = (t_chunk *)(g->end + size);
  tmp->size = g->size - size - ROUND_HEAP_SIZE(size);
  tmp->next = g->next;
  tmp->free = 1;
  tmp->prev = g;
  g->size = size;
  g->next = tmp;
}

t_chunk     *glue_given_block(t_chunk *g) {
  if (g->next && g->next->free) {
    g->size += ROUND_HEAP_SIZE(g->size) + g->next->size;
    g->next = g->next->next;
    if (g->next) {
      g->next->prev = g;
    }
  }

  return (g);
}

void *malloc(size_t size) {
  (void)size;
}

