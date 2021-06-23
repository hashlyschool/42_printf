#include "../includes/ft_printf.h"

char	ft_treat_minus(t_spec *spec, char mode, char *c, size_t len_c)
{
	char	*new_str;

	if (spec->minus + mode == 1)
	{
		new_str = ft_strjoin_len(spec->final_str, c, spec->len, len_c);
		if (!new_str)
			return (0);
		spec->len += len_c;
		free(spec->final_str);
		spec->final_str = new_str;
		return (1);
	}
	return (0);
}

void	ft_treat_width(t_spec *spec, int width, int len_str, int zero)
{
	char	*new_str;

	while (width - len_str > 0)
	{
		if (zero)
			new_str = ft_strjoin_len(spec->final_str, "0\0", spec->len, 1);
		else
			new_str = ft_strjoin_len(spec->final_str, " \0", spec->len, 1);
		spec->len++;
		if (!new_str)
		{
			spec->error = 1;
			return ;
		}
		free(spec->final_str);
		spec->final_str = new_str;
		width -= 1;
	}
	return ;
}
