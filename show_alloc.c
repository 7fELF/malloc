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

void show_alloc_mem()
{
  printf("\n----------------\n");
  printf("%p", sbrk(0));
  t_chunk *chunk;

  chunk = g_first_chunk;
  while (chunk) {
    printf("%p %6lu %2lu \n", chunk + 1, chunk->size, chunk->free);
    chunk = chunk->next;
  }
  printf("----------------\n");
}
