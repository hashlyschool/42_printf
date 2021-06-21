#include "../includes/ft_printf.h"

void	ft_write_c(t_spec *spec)
{
	char	*new_str;
	char	c;

	c = (char)va_arg(spec->ap, int);
	if (spec->minus)
	{
		new_str = ft_strjoin_len(spec->final_str, &c, spec->len, 1);
		spec->len++;
		free(spec->final_str);
		spec->final_str = new_str;
	}
	ft_treat_width(spec, spec->width, 1, 0);
	if (!spec->minus)
	{
		new_str = ft_strjoin_len(spec->final_str, &c, spec->len, 1);
		spec->len++;
		free(spec->final_str);
		spec->final_str = new_str;
	}
	if (!new_str)
		spec->error = 1;
	return ;
}
