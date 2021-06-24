#include "../includes/ft_printf.h"

#include <stdio.h>

static int	ft_free_struct(t_spec *spec)
{
	if (spec->final_str)
		free(spec->final_str);
	return (-1);
}

static void	ft_init_struct(t_spec	*spec)
{
	spec->minus = 0;
	spec->zero = 0;
	spec->okto = 0;
	spec->space = 0;
	spec->plus = 0;
	spec->width = 0;
	spec->width_star = 0;
	spec->prec = -1;
	spec->prec_star = 0;
	spec->size[0] = 0;
	spec->size[1] = 0;
	spec->type = 0;
	spec->list_type = "cspdiuxX%nfge";
	return ;
}

static int	print_final_str(t_spec	*spec)
{
	if (spec->error)
		return (ft_free_struct(spec));
	if (!spec->final_str)
		return (ft_free_struct(spec));
	write(1, spec->final_str, spec->len);
	ft_free_struct(spec);
	return (spec->len);
}

	/*
		принимает указатель на начало, либо символ после %
		записывает ошибку в случае нужды
		записывает в final_str все до %
		возвращает указатель на %+1 в исходной строке
		или конец файла
	*/

static char	*find_pers(char *str, t_spec *spec)
{
	char	*ptr;
	char	*str1;
	char	*new_str;
	char	*old_str;

	ptr = str;
	while (*ptr && (*ptr) != '%')
		ptr++;
	str1 = ft_substr(str, 0, ptr - str);
	if (!str1)
	{
		spec->error = 1;
		return (ptr);
	}
	old_str = spec->final_str;
	new_str = ft_strjoin_len(spec->final_str, str1, spec->len, ft_strlen(str1));
	spec->len += ft_strlen(str1);
	free(old_str);
	if (!new_str)
		spec->error = 1;
	spec->final_str = new_str;
	free(str1);
	if (*ptr == '%')
		ptr++;
	return (ptr);
}

int	ft_printf(const char *str, ...)
{
	t_spec	spec;
	char	*ptr;

	if (str)
	{
		spec.error = 0;
		spec.len = 0;
		spec.final_str = (char *)malloc(sizeof(char) * 1);
		va_start(spec.ap, str);
		ptr = (char *)str;
		while (*ptr && !spec.error)
		{
			ft_init_struct(&spec);
			ptr = find_pers(ptr, &spec);
			if (*(ptr - 1) == '%')
			{
				if (*ptr == '%')
					ft_write_pers(&spec);
				else
				{
					ptr = ft_parse_spec(ptr, &spec);
					if (!spec.error && spec.type)
						ft_write_arg(&spec);
				}
			}
		}
		va_end(spec.ap);
		return (print_final_str(&spec));
	}
	return (-1);
}
