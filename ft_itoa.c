#include "libft.h"

static size_t	digit_count(long n)
{
	size_t	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	num;
	size_t	len;
	char	*result;

	num = n;
	len = digit_count(num);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (num < 0)
	{
		result[0] = '-';
		num = -num;
	}
	while (len > 0)
	{
		result[--len] = (char)('0' + num % 10);
		num /= 10;
		if (num == 0)
			break ;
	}
	return (result);
}
