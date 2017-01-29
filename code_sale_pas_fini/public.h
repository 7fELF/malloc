#ifndef PUBLIC_H_
# define PUBLIC_H_

#include <unistd.h>

//void *malloc(size_t size);
void free(void *ptr);
void *realloc(void *ptr, size_t size);

#endif /* !PUBLIC_H_ */
