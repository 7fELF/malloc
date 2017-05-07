#include <string.h>
#include "private.h"

void *calloc(size_t count, size_t size)
{
  void *ptr;

  ptr = malloc(count * size);
  if (ptr)
    memset(ptr, 0, count * size);
  return (ptr);
}
