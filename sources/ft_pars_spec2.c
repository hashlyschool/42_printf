#include "../includes/ft_printf.h"

char	*ft_check_size(char *ptr, t_spec *spec)
{
	/*
		ptr - указатель на первый символ размера
		или на место где он должен быть
		возвращает символ после размера или ptr
	*/
	if (*ptr == 'l' || *ptr == 'h')
	{
		spec->size[0] = *ptr++;
		if (*ptr == *(ptr - 1))
			spec->size[1] = *ptr++;
	}
	return (ptr);
}