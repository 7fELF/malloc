/*
** malloc.h for PSU_2016_malloc in /Users/pichar_v/Documents/tek2/PSU_2016_malloc
**
** Made by Valentin Pichard
** Login   <valentin.pichard@epitech.eu>
**
** Started on  Fri Jan 27 15:07:09 2017 Solomon Hykes
** Last update Fri Jan 27 16:29:04 2017 Antoine Baudrand
*/

#ifndef MALLOC_H_
# define MALLOC_H_

/* Global headers */
#include <stdlib.h>
#include <unistd.h>

/* Asked functions */
void show_alloc_mem();
void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);


#endif /* !MALLOC_H_ */
