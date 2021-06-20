#include "../includes/ft_printf.h"

#include <stdio.h>

static int	free_struct(t_spec *spec, int error)
{
	if (spec->final_str)
		free(spec->final_str);
	return (error * -1);
}

static void	init_struct(t_spec	*spec)
{
	spec->minus = 0;
	spec->zero = 0;
	spec->okto = 0;
	spec->space = 0;
	spec->plus = 0;
	spec->width = 0;
	spec->star = 0;
	spec->prec = 0;
	spec->size[0] = 0;
	spec->size[1] = 0;
	spec->type = 0;
	return ;
}

static int	print_final_str(t_spec	*spec)
{
	int	len;

	if (spec->error)
		return (free_struct(spec, 1));
	if (!spec->final_str)
		return (free_struct(spec, 1));
	len = ft_strlen(spec->final_str);
	ft_putstr_fd(spec->final_str, 1);
	free_struct(spec, 0);
	return (len);
}

static char	*find_pers(char *str, t_spec *spec)
{
	/*
		принимает указатель на начало, либо символ после % 
		записывает ошибку в случае нужды
		записывает в final_str все до %
		возвращает указатель на %+1 в исходной строке
		или конец файла
	*/
	char	*ptr;
	char	*substr;
	char	*new_str;
	char	*old_str;

	ptr = str;
	while (*ptr && (*ptr) != '%')
		ptr++;
	substr = ft_substr(str, 0, ptr - str);
	if (!substr)
	{
		spec->error = 1;
		return (ptr);
	}
	old_str = spec->final_str;
	new_str = ft_strjoin(spec->final_str, substr);
	free(old_str);
	if (!new_str)
		spec->error = 1;
	spec->final_str = new_str;
	free(substr);
	return (ptr);
}

int			ft_printf(const char *str, ...)
{
	t_spec	spec;
	char	*ptr;

	if(str)
	{
		spec.error = 0;
		spec.list_type = "cspdiuxX%nfge";
		spec.final_str = (char *)malloc(sizeof(char) * 1);
		*(spec.final_str) = '\0';
		va_start(spec.ap, str);
		ptr = (char *)str;
		while(*ptr && !spec.error)
		{
			init_struct(&spec);
			ptr = find_pers(ptr, &spec);
			ptr = ft_parse_spec(ptr, &spec);
			if (!spec.error)
				ft_write_arg(&spec);
		}
		va_end(spec.ap);
		return (print_final_str(&spec));
	}
	return(-1);
}