#include "../includes/ft_printf.h"

void	ft_write_pers(t_spec *spec)
{
	char	c;
	char	count_treat_minus;

	count_treat_minus = 0;
	c = '%';
	count_treat_minus += ft_treat_minus(spec, 0, &c, 1);
	ft_treat_width(spec, spec->width, 1, 0);
	count_treat_minus += ft_treat_minus(spec, 1, &c, 1);
	if (count_treat_minus == 0)
		spec->error = 1;
	return ;
}
