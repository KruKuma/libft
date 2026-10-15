#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t len)
{
    unsigned char       *d;
    const unsigned char *s;
    size_t              i;

    if (dest == src || len == 0)
        return (dest);
    d = (unsigned char *)dest;
    s = (const unsigned char *)src;
    if (d < s)
        return (ft_memcpy(dest, src, len));
    i = len;
    while (i > 0)
    {
        i--;
        d[i] = s[i];
    }
    return (dest);
}
