/*
** main.c for PSU_2016_malloc in /home/antoine/PSU_2016_malloc
**
** Made by Antoine Baudrand
** Login   <antoine.baudrand@epitech.eu>
**
** Started on  mar. janv. 31 11:20:18 2017 Antoine Baudrand
** Last update mar. janv. 31 11:20:18 2017 Antoine Baudrand
*/

#include "malloc.h"

int main()
{
  size_t sz;
  t_chunk *c;
  char *m;

  while (1) {
    sz = random() % (1 << 21);
    m = (char*) malloc(sz);
    c = ((t_chunk*)m) - 1;
    if (c->size < sz) break;
    sz = ROUND_CHUNK_SIZE(sz);
    for (size_t i; i < sz; i++)
    {
      m[i] = 42;
      if (m[i] != 42) break;
    }
    if (random() % 2)
      free(m);
    show_alloc_mem();
  }
}
