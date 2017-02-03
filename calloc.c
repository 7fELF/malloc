/*
** calloc.c for PSU_2016_malloc in /home/antoine/PSU_2016_malloc
**
** Made by Antoine Baudrand
** Login   <antoine.baudrand@epitech.eu>
**
** Started on  ven. févr. 03 14:16:28 2017 Antoine Baudrand
** Last update ven. févr. 03 14:16:28 2017 Antoine Baudrand
*/
#include "private.h"
#include <string.h>

void *calloc(size_t count, size_t size)
{
  void *ptr;

  ptr = malloc(count * size);
  if (ptr)
    memset(ptr, 0, count * size);
  return ptr;
}
