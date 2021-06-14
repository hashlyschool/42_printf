#include "libft.h"

static size_t	ft_find_len(int n)
{
	size_t	len;

	len = 1;
	n /= 10;
	while (n)
	{
		n /= 10;
		len *= 10;
	}
	return (len);
}

void	ft_putnbr_fd(int nbr, int fd)
{
	size_t	len;

	if (nbr == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	len = ft_find_len(nbr);
	while (len > 0)
	{
		ft_putchar_fd(nbr / len + '0', fd);
		nbr -= ((nbr / len) * len);
		len /= 10;
	}
	return ;
}
