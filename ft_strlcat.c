#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t dlen;
    size_t slen;
    size_t i;

    dlen = 0;
    while (dlen < dstsize && dst[dlen] != '\0')
        dlen++;
    slen = ft_strlen(src);
    if (dlen == dstsize)
        return (dstsize + slen);
    i = 0;
    while (src[i] != '\0' && dlen + i + 1 < dstsize)
    {
        dst[dlen + i] = src[i];
        i++;
    }
    dst[dlen + i] = '\0';
    return (dlen + slen);
}
