#include "../includes/ft_printf.h"

void	ft_write_s(t_spec *spec)
{
	char	*c;
	size_t	len_c;
	char	count_treat_minus;
	char	null;

	count_treat_minus = 0;
	c = va_arg(spec->ap, char *);
	if (c == NULL)
	{
		if (spec->prec < 6 && spec->prec > 0)
			c = ft_strdup("");
		else
			c = ft_strdup("(null)");
		null = 1;
	}
	else
		null = 0;
	len_c = ft_strlen(c);
	if (spec->prec >= 0 && len_c > (size_t)spec->prec)
		len_c = spec->prec;
	count_treat_minus += ft_treat_minus(spec, 0, c, len_c);
	ft_treat_width(spec, spec->width, len_c, spec->zero);
	count_treat_minus += ft_treat_minus(spec, 1, c, len_c);
	if (null)
		free(c);
	if (count_treat_minus == 0)
		spec->error = 1;
	return ;
}
