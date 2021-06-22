#include "../includes/ft_printf.h"

void	ft_write_s(t_spec *spec)
{
	char	*new_str;
	char	*c;
	size_t	len_c;

	c = va_arg(spec->ap, char*);
	len_c = ft_strlen(c);
	if (spec->minus)
	{
		new_str = ft_strjoin_len(spec->final_str, c, spec->len, len_c);
		spec->len += len_c;
		free(spec->final_str);
		spec->final_str = new_str;
	}
	ft_treat_width(spec, spec->width, spec->minus, spec->zero);
	if (!spec->minus)
	{
		new_str = ft_strjoin_len(spec->final_str, c, spec->len, len_c);
		spec->len += len_c;
		free(spec->final_str);
		spec->final_str = new_str;
	}
	if (!new_str)
		spec->error = 1;
	return ;
}
