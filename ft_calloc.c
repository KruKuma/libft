#include "libft.h"
#include <stdlib.h>

void *ft_calloc(size_t nmemb, size_t size)
{
    void *ptr;
    size_t total;

    if (size != 0 && nmemb > (size_t)-1 / size)
        return (NULL);
    total = nmemb * size;
    if (total == 0)
        ptr = malloc(1);
    else
        ptr = malloc(total);
    if (ptr == NULL)
        return (NULL);
    ft_bzero(ptr, total);
    return (ptr);
}
