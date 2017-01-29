#ifndef MALLOC_H_
# define MALLOC_H_

#include "public.h"

/*
 * The heap size is a multiple of this value
 */
#define MIN_BLOCK_SIZE (1 << 12) //4096 - Must be a power of 2

/*
 * Round up size to a multiple of MIN_BLOCK_SIZE using a bitwise OR
 * Example for extend_heap(5) and MIN_BLOCK_SIZE = (1 << 2) :
 * size                 = 5 = 0b101
 * MIN_BLOCK_SIZE       = (1 << 2) = 4 = 0b100
 * (MIN_BLOCK_SIZE - 1) = 3 = 0b011
 *
 * (size | (MIN_BLOCK_SIZE - 1))      = 0b101 | 0b011 = 0b111
 * (size | (MIN_BLOCK_SIZE - 1)) + 1  = 0b111 + 1 = 0b1000 = 8
 */
#define ROUND_HEAP_SIZE(size) (size | (MIN_BLOCK_SIZE - 1)) + 1

typedef struct s_memory_chunk {
  void *ptr;
  size_t size;
  long free;
} t_memory_chunk;

/*
 * Daufault size of the t_memory->chunks array
 */

#define DEFAULT_CHUNK_ARRAY_SIZE 8

typedef struct s_memory {
  t_memory_chunk *chunks;
  size_t len;
  size_t size;
} t_memory;

#endif /* !MALLOC_H_ */
