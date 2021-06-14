#include "libft.h"

int	ft_atoi(const char *str)
{
	int		n;
	int		flag;
	size_t	len_num;

	n = 0;
	flag = 1;
	len_num = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			flag *= -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str++ - '0');
		if (len_num++ > 12 && flag == 1)
			return (-1);
		else if (len_num > 12 && flag == -1)
			return (0);
	}
	return (n * flag);
}
