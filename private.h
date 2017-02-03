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

#include "public.h"

/*
** Round up n to a multiple of m
** m must be a power of two
*/
# define ROUND_UP_TO(n, m) ((n) | (m - 1)) + 1

/*
** Must be a power of 2
*/
# define PAGESIZE (1 << 20)
# define WORD sizeof(void*)

# define ROUND_TO_PAGESIZE(size) ROUND_UP_TO(size, PAGESIZE)
# define ROUND_TO_WORD(size) ROUND_UO_TO(size, WORD)


/*
** Struct representing each allocated chunk
*/
typedef struct s_chunk t_chunk;
struct     s_chunk {
  size_t   size;
  long     free;
  t_chunk  *next;
  t_chunk  *prev;
  t_chunk  *next_free;
  t_chunk  *prev_free;
};

# define T_CHUNK_SIZE sizeof(t_chunk)

/*
** Add a chunk in the chunks list
*/
void add_chunk(t_chunk *);

/*
** Split a chunk in two parts,
** the first part have have the size given as second argument
** the second part takes whats left, if its not enough to make a chunk,
** the chunk is not splitted.
** the first part is marked as allocated (always, even if the chunk is not splitted)
** and the second as free
*/
void split_chunk(t_chunk *, size_t size);

/*
** Merge the chunk given as argument
** with the NEXT() chunk
*/
void merge_with_next_chunk(t_chunk*);

/*
** Mark the chunk as allocated
*/
void alloc_chunk(t_chunk*);

/*
** Mark the chunk as freed
** and merge surrounding free chunks
*/
void free_chunk(t_chunk*);

/*
** Add a chunk to the free_chunks list
*/
void add_free_chunk(t_chunk*);

/*
** Remove a chunk from the free_chunks list
*/
void remove_free_chunk(t_chunk*);

/*
** List helpers macros
*/
# define NEXT(list) list = list->next
# define PREV(list) list = list->prev
# define NEXT_FREE(list) list = list->next_free
# define PREV_FREE(list) list = list->prev_free
# define CHUNK_END_PTR(chunk) (((char*)(chunk)) + T_CHUNK_SIZE + size)


/*
** Global variable containing the last element of the chunks list.
** It means that you have to do use PREV() to browse the list.
*/
extern t_chunk *g_chunks;

/*
** Global variable containing the last element of the free chunks list
** It means that you have to do use PREV_FREE() to browse the list.
*/
extern t_chunk *g_free_chunks;

#endif /* !PRIVATE_H_ */
