#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    const char *last;

    last = NULL;
    while (1)
    {
        if ((unsigned char)*s == (unsigned char)c)
            last = s;
        if (*s == '\0')
            break ;
        s++;
    }
    return ((char *)last);
}
