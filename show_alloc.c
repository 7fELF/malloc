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
  //write(1, sbrk(0), 10);
  printf("\n----------------\n");
  printf("break : 0x%lX\n", (unsigned long)sbrk(0));
  t_chunk *chunk;

  chunk = g_first_chunk;
  while (chunk) {
    printf("0x%lX - 0x%lX %lu bytes \n", (unsigned long)chunk, (unsigned long)(chunk + chunk->size), chunk->size);
    chunk = chunk->next;
  }
  printf("----------------\n");
}
