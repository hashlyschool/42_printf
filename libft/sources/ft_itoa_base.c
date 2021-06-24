#include "../includes/libft.h"

static int	ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

static int	ft_find_size_num(int value, int base)
{
	int	tmp;
	int	size;

	tmp = value;
	size = 0;
	while (tmp)
	{
		tmp /= base;
		size++;
	}
	return (size);
}

static int	ft_find_size_num_u(unsigned long long value, int base)
{
	unsigned long long	tmp;
	int					size;

	tmp = value;
	size = 0;
	while (tmp)
	{
		tmp /= base;
		size++;
	}
	return (size);
}

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	int		size;
	char	*tab;
	int		flag;

	flag = 0;
	size = 0;
	tab = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (NULL);
	if (value < 0 && base == 10)
		flag = 1;
	size = ft_find_size_num(value, base) + flag;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = tab[ft_abs(value % base)];
		size--;
		value /= base;
	}
	return (str);
}

char	*ft_itoa_base_u(unsigned long long value, int base)
{
	char	*str;
	int		size;
	char	*tab;

	if (value == 0)
		return (ft_strdup("0"));
	size = 0;
	tab = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (NULL);
	size = ft_find_size_num_u(value, base);
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	while (size)
	{
		str[size - 1] = tab[value % base];
		size--;
		value /= base;
	}
	return (str);
}
