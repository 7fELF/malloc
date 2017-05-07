#include <stdio.h>
#include <inttypes.h>
#include "private.h"

void       show_alloc_mem()
{
  t_chunk  *chunk;

  printf("break : 0x%" PRIXPTR "\n", (uintptr_t) sbrk(0));
  chunk = g_chunks;
  while (chunk) {
    printf("0x%" PRIXPTR " - 0x%" PRIXPTR " : %lu bytes \n",
        (uintptr_t) (chunk + 1),
        (uintptr_t) (((char*)chunk) + T_CHUNK_SIZE + chunk->size), chunk->size);
    chunk = chunk->next;
  }
}
