#include "../includes/ft_printf.h"

void	ft_set_flag(char flag, t_spec *spec)
{
	if (flag == '-')
		spec->minus = 1;
	else if (flag == '0')
		spec->zero = 1;
	else if (flag == '#')
		spec->okto = 1;
	else if (flag == ' ')
		spec->space = 1;
	else if (flag == '+')
		spec->plus = 1;
	return ;
}

/*
	ptr - указатель на первый символ размера
	или на место где он должен быть
	возвращает символ после размера или ptr
*/

char	*ft_check_size(char *ptr, t_spec *spec)
{
	if (*ptr == 'l' || *ptr == 'h')
	{
		spec->size[0] = *ptr++;
		if (*ptr == *(ptr - 1))
			spec->size[1] = *ptr;
	}
	return (ptr);
}
