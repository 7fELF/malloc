/*
** private.h for PSU_2016_malloc in /home/antoine/PSU_2016_malloc
**
** Made by Antoine Baudrand
** Login   <antoine.baudrand@epitech.eu>
**
** Started on  jeu. févr. 02 21:12:07 2017 Antoine Baudrand
** Last update jeu. févr. 02 21:12:07 2017 Antoine Baudrand
*/

#ifndef PRIVATE_H_
# define PRIVATE_H_

# include "public.h"
# include <unistd.h>
# include <stddef.h>

/*
** Round up n to a multiple of m
** m must be a power of two
*/
# define ROUND_UP_TO(n, m) ((n) | (m - 1)) + 1

/*
** Must be a power of 2
*/
# define PAGESIZE (1 << 21)
# define WORD sizeof(void*)

# define ROUND_TO_PAGESIZE(size) ROUND_UP_TO(size, PAGESIZE)
# define ROUND_TO_WORD(size) ROUND_UP_TO(size, WORD)

/*
** Struct representing each allocated chunk
*/
typedef struct s_chunk t_chunk;
struct     s_chunk {
  size_t   size;
  long     free;
  t_chunk  *prev;
  t_chunk  *next;
};

# define T_CHUNK_SIZE sizeof(t_chunk)

/*
** List helpers macros
*/
# define NEXT(list) list = list->next
# define PREV(list) list = list->prev
# define CHUNK_END_PTR(chunk) (((char*)(chunk)) + T_CHUNK_SIZE + chunk->size)
# define CHUNK_DATA(chunk) ((void*)(chunk + 1))
# define GET_CHUNK_FROM_DATA_PTR(ptr) (((t_chunk*)ptr) - 1)

/*
** Global variable containing the first element of the chunks list.
*/
extern t_chunk *g_chunks;

#endif /* !PRIVATE_H_ */
