#include "../includes/ft_printf.h"

static void	check_width_spec_star(t_spec *spec)
{
	if (spec->width_star)
		spec->width = (int)va_arg(spec->ap, int);
	if (spec->prec_star)
	{
		spec->prec = (int)va_arg(spec->ap, int);
		if (spec->prec < 0)
			spec->prec = -1;
		if (spec->prec != -1 && ft_strchr("diouxX", spec->type))
			spec->zero = 0;
	}
	if (spec->width < 0)
	{
		spec->minus = 1;
		if (spec->zero)
			spec->zero = 0;
		spec->width *= -1;
	}
	return ;
}

char	*ft_strjoin_len(char *s1, char *s2, size_t len1, size_t len2)
{
	char	*ptr;
	char	*start;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = len1 + len2;
	ptr = (char *)malloc(sizeof(*s1) * (len + 1));
	if (!ptr)
		return (NULL);
	start = ptr;
	while (len1--)
		*ptr++ = *s1++;
	while (len2--)
		*ptr++ = *s2++;
	*ptr = 0;
	return (start);
}

/*
	spec содержит аргумент и флаги
	Обрабатывает аргумент в зависимости от спецификатора
	записывает в финальную строку
	записывает ошибку в случае нужды
*/

void	ft_write_arg(t_spec *spec)
{
	check_width_spec_star(spec);
	if (spec->type == 'c')
		ft_write_c(spec);
	else if (spec->type == 's')
		ft_write_s(spec);
	else if (spec->type == 'p')
		ft_write_p(spec);
	else if (spec->type == 'd' || spec->type == 'i')
		ft_write_d_i(spec);
	else if (spec->type == 'u')
		ft_write_u(spec);
	return ;
}

	/*
	else if (spec->type == 'x')
		ft_write_x(spec);
	else if (spec->type == 'X')
		ft_write_X(spec);
	else if (spec->type == '%')
		ft_write_perc(spec);*/
