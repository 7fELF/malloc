/*
** malloc.h for PSU_2016_malloc in /tekpi/PSU_2016_malloc
**
** Made by Valentin Pichard
** Login   <valentin.pichard@epitech.eu>
**
** Started on  Fri Jan 27 15:07:09 2017 Solomon Hykes
** Last update Fri Jan 27 16:29:04 2017 Antoine Baudrand
*/

#ifndef MALLOC_H_
# define MALLOC_H_

/*
** Global headers
*/
# include <stdlib.h>
# include <unistd.h>

/*
** Asked functions
*/
void show_alloc_mem(void);
void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);

/*
** Round up size to a multiple of MIN_BLOCK_SIZE using a bitwise OR
** Example for extend_heap(5) and MIN_BLOCK_SIZE = (1 << 2) :
** size                 = 5 = 0b101
** MIN_BLOCK_SIZE       = (1 << 2) = 4 = 0b100
** (MIN_BLOCK_SIZE - 1) = 3 = 0b011
**
** (size | (MIN_BLOCK_SIZE - 1))      = 0b101 | 0b011 = 0b111
** (size | (MIN_BLOCK_SIZE - 1)) + 1  = 0b111 + 1 = 0b1000 = 8
*/
# define MIN_BLOCK_SIZE (1 << 20) // Must be a power of 2
# define ROUND_HEAP_SIZE(size) ((size) | (MIN_BLOCK_SIZE - 1)) + 1
# define ROUND_CHUNK_SIZE(size) ((size | 7) + 1)

typedef struct s_chunk t_chunk;

struct     s_chunk {
  size_t   size;
  long     free;
  t_chunk  *prev;
  t_chunk  *next;
};

# define METADATA_SIZE (sizeof(t_chunk))

extern t_chunk *g_first_chunk;

#endif /* !MALLOC_H_ */
