/*
** show_alloc.c for PSU_2016_malloc in /Users/pichar_v/Documents/tek2
**
** Made by Valentin Pichard
** Login   <valentin.pichard@epitech.eu>
**
** Started on  Fri Jan 27 15:07:09 2017 Solomon Hykes
** Last update Fri Jan 27 15:07:09 2017 Solomon Hykes
*/

#include "private.h"
#include <stdio.h>
#include <inttypes.h>

void show_alloc_mem()
{
  t_chunk *chunk;

  printf("break : 0x%" PRIXPTR "\n", (uintptr_t) sbrk(0));
  chunk = g_chunks;
  while (chunk) {
    printf("0x%" PRIXPTR " - 0x%" PRIXPTR " : %lu bytes \n",
        (uintptr_t) (chunk + 1),
        (uintptr_t) (((char*)chunk) + T_CHUNK_SIZE + chunk->size), chunk->size);
    chunk = chunk->next;
  }
}
