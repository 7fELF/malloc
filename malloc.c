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

t_chunk     *find_block(t_chunk *first_block, size_t size) {
  t_chunk   *tmp;

  tmp = first_block;
  while (tmp && (tmp->free && tmp->size >= size)) {
    tmp = tmp->next;
  }

  return (tmp);
}

void *malloc(size_t size) {
}

