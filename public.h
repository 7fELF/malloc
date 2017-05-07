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
