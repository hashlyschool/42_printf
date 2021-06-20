#include "../includes/ft_printf.h"

void	ft_write_c(t_spec *spec)
{
	char	*new_str;
	char	c[2];

	c[0] = (char)va_arg(spec->ap, int);
	c[1] = 0;
	if (spec->minus)
	{
		new_str = ft_strjoin(spec->final_str, c);
		free(spec->final_str);
		spec->final_str = new_str;
	}
	ft_treat_width(spec, spec->width, 1, 0);
	if (!spec->minus)
	{
		new_str = ft_strjoin(spec->final_str, c);
		free(spec->final_str);
		spec->final_str = new_str;
	}
	if (!c || !new_str)
		spec->error = 1;
	return ;
}