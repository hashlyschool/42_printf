#include "../includes/ft_printf.h"

int ft_printf(const char *str, ...)
{
	int		count;
	va_list	ap;
	char	*ptr;

	count = -1;
	if (*str)
	{
		ptr = str;
		va_start(ap, str);
		while (*ptr)
			count += read_print(ptr, ap);
		va_end(ap);
	}
	return (count);
}