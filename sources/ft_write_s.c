#include "../includes/ft_printf.h"

void	ft_write_s(t_spec *spec)
{
	char	*c;
	size_t	len_c;
	char	count_treat_minus;

	count_treat_minus = 0;
	c = va_arg(spec->ap, char *);
	len_c = ft_strlen(c);
	if (spec->prec >= 0 && len_c > (size_t)spec->prec)
		len_c = spec->prec;
	count_treat_minus += ft_treat_minus(spec, 0, c, len_c);
	ft_treat_width(spec, spec->width, len_c, spec->zero);
	count_treat_minus += ft_treat_minus(spec, 1, c, len_c);
	if (count_treat_minus == 0)
		spec->error = 1;
	return ;
}
