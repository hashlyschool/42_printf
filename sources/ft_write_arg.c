#include "../includes/ft_printf.h"

void	ft_write_arg(t_spec *spec)
{
	/*
		spec содержит аргумент и флаги
		Обрабатывает аргумент в зависимости от спецификатора
		записывает в финальную строку
		записывает ошибку в случае нужды
	*/
	if (spec->type == 'c')
		ft_write_c(spec);
	/*else if (spec->type == 's')
		ft_write_s(spec);
	else if (spec->type == 'p')
		ft_write_p(spec);
	else if (spec->type == 'd')
		ft_write_d(spec);
	else if (spec->type == 'i')
		ft_write_i(spec);
	else if (spec->type == 'u')
		ft_write_u(spec);
	else if (spec->type == 'x')
		ft_write_x(spec);
	else if (spec->type == 'X')
		ft_write_X(spec);
	else if (spec->type == '%')
		ft_write_perc(spec);
		*/
	return ;
}