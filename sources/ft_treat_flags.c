#include "../includes/ft_printf.h"

void	ft_treat_width(t_spec *spec, int width, int minus, int zero)
{
	char	*new_str;

	while (width - minus > 0)
	{
		if (zero)
			new_str = ft_strjoin(spec->final_str, "0\0");
		else
			new_str = ft_strjoin(spec->final_str, " \0");
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
