#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	digit;

	num = (long)n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	if (num >= 10)
		ft_putnbr_fd((int)(num / 10), fd);
	digit = (char)('0' + (num % 10));
	write(fd, &digit, 1);
}
