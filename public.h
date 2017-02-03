/*
** public.h for PSU_2016_malloc in /home/antoine/PSU_2016_malloc
**
** Made by Antoine Baudrand
** Login   <antoine.baudrand@epitech.eu>
**
** Started on  jeu. févr. 02 21:12:01 2017 Antoine Baudrand
** Last update jeu. févr. 02 21:12:01 2017 Antoine Baudrand
*/

#ifndef PUBLIC_H_
# define PUBLIC_H_

/*
** size_t
*/
# include <stddef.h>

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);

void show_alloc_mem(void);

#endif /* !PUBLIC_H_ */
