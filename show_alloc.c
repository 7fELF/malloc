/*
** show_alloc.c for PSU_2016_malloc in /Users/pichar_v/Documents/tek2
**
** Made by Valentin Pichard
** Login   <valentin.pichard@epitech.eu>
**
** Started on  Fri Jan 27 15:07:09 2017 Solomon Hykes
** Last update Fri Jan 27 15:07:09 2017 Solomon Hykes
*/

#include "malloc.h"
#include <stdio.h>

void show_alloc_mem() {
  t_memory *memory = get_memory();
  t_memory_chunk *chunk;
  size_t i;

  printf("break : %p\n", sbrk(0));
  i = 0;
  while (i < memory->len) {
    chunk = memory->chunks + i;
    printf("%p - %p : %ld bytes %ld\n",
        chunk->ptr,
        (void*) ((char*)chunk->ptr + chunk->size),
        chunk->size,
        chunk->free);
    i += 1;
  }
}
