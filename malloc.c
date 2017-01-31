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

static void add_chunk(t_memory *memory, void *ptr, size_t size, long free) {
  t_memory_chunk *chunk;

  if ((memory->size - 2) <= memory->len) {
    memory->size += 2;
    // Realloc chunk array using malloc
    memory->size -= 2;
  }
  chunk = &memory->chunks[memory->len];
  chunk->ptr = ptr;
  chunk->size = size;
  chunk->free = free;
  memory->len += 1;
}

static void *alloc_chunk(t_memory *memory, size_t index, size_t size) {
  t_memory_chunk *chunk;
  chunk = memory->chunks + index;
  if (chunk->size == size)
  {
    chunk->free = 0;
    return chunk->ptr;
  }
  if ((memory->size - 2) <= memory->len)
  {
    memory->size += 2;
    // Realloc chunk array using malloc
    memory->size -= 2;
  }
  memmove(chunk + 2, chunk + 1,
      sizeof(t_memory_chunk) * (memory->len - index - 1));
  chunk[1].ptr = ((char*) chunk->ptr) + size;
  chunk[1].size = chunk->size - size;
  chunk[1].free = 1;
  chunk->free = 0;
  chunk->size = size;
  memory->len += 1;
  return chunk;
}


static void free_chunk(t_memory *memory, size_t index) {
  t_memory_chunk *chunks;

  chunks = memory->chunks;
  chunks[index].free = 1;
  if (index < memory->len && chunks[index + 1].free) {
    chunks[index].size += chunks[index + 1].size;
    memmove(chunks + index + 1, chunks + index + 2,
        sizeof(t_memory_chunk) * (memory->len - index - 2));
    memory->len -= 1;
  }
  if (index > 0 && chunks[index - 1].free) {
    chunks[index - 1].size += chunks[index].size;
    memmove(chunks + index, chunks + index + 1,
        sizeof(t_memory_chunk) * (memory->len - index - 1));
    memory->len -= 1;
  }
}

t_memory *get_memory() {
  static t_memory memory;
  if (memory.size == 0) {
    memory.len = 0;
    memory.size = DEFAULT_CHUNK_ARRAY_SIZE;
    memory.chunks = (t_memory_chunk*) sbrk((intptr_t) ROUND_HEAP_SIZE(sizeof(t_memory_chunk) * memory.size));
    add_chunk(&memory, memory.chunks, sizeof(t_memory_chunk) * memory.size, 0);
  }
  return &memory;
}

void *malloc(size_t size) {
  write(2, "malloc\n", 7);
  t_memory *memory = get_memory();
  size_t i = 0;

  while (i < memory->len) {
    if (memory->chunks[i].free
        && memory->chunks[i].size >= size) {
      return alloc_chunk(memory, i, size);
    }
    i += 1;
  }
  size_t addToHeap = ROUND_HEAP_SIZE(size);
  add_chunk(memory, sbrk((intptr_t)addToHeap), addToHeap, 1);
  return alloc_chunk(memory, memory->len - 1, size);
}

