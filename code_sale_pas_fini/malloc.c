/*
** malloc.c for malloc in /home/antoine/malloc
**
** Made by Antoine Baudrand
** Login   <antoine.baudrand@epitech.eu>
**
** Started on  ven. janv. 27 13:30:04 2017 Antoine Baudrand
** Last update ven. janv. 27 13:30:04 2017 Antoine Baudrand
*/

#include "private.h"
#include <string.h>
#include <stdio.h>

static void show_alloc_mem(t_memory *memory) {
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

static void add_chunk(t_memory *memory, void *ptr, size_t size, long free) {
  t_memory_chunk *chunk;

  if ((memory->size - 2) <= memory->len) {
    memory->size += 2;
    // Realloc chunk array using malloc
    memory->size -= 2;
  }
  chunk = memory->chunks + memory->len;
  chunk->ptr = ptr;
  chunk->size = size;
  chunk->free = free;
  memory->len += 1;
}


static void free_chunk(t_memory *memory, size_t index) {
  t_memory_chunk *chunks;

  chunks = memory->chunks;
  chunks[index].free = 1;
  if (index < memory->len && chunks[index + 1].free) {
    chunks[index].size += chunks[index + 1].size;
    memmove(chunks + index + 1, chunks + index + 2,
        sizeof(t_memory_chunk) * memory->len - index - 1);
    memory->len -= 1;
  }
  if (index > 0 && chunks[index - 1].free) {
    chunks[index - 1].size += chunks[index].size;
    memmove(chunks + index, chunks + index + 1,
        sizeof(t_memory_chunk) * memory->len - index);
    memory->len -= 1;
  }
}


static t_memory *get_memory();

static t_memory *get_memory() {
  static t_memory memory;
  if (memory.size == 0) {
    memory.len = 0;
    memory.size = DEFAULT_CHUNK_ARRAY_SIZE;
    memory.chunks = (t_memory_chunk*) sbrk((intptr_t) ROUND_HEAP_SIZE(sizeof(t_memory) * memory.size));
    add_chunk(memory.chunks, sizeof(t_memory) * memory.size, 0);
  }
  return &memory;
}

void *malloc(size_t size) {
  t_memory *memory = get_memory();
  int i;

  while (i < memory->len) {{
    if (memory->chunks[i].free && memory->chunks[i].size >= size) {
      memory->chunks[i].free = 0;
    }
  }
}

int main() {
  int *a = (int*) malloc(sizeof(int));
}
