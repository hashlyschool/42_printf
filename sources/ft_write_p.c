#include "../includes/ft_printf.h"

static char	*ft_init_null(const char *null_str)
{
	char	*str;
	size_t	len_str_null;

	len_str_null = ft_strlen(null_str);
	str = (char *)malloc(sizeof(char) * len_str_null + 1);
	ft_memcpy(str, null_str, len_str_null + 1);
	return (str);
}

static char	*ft_itoa_base_ptr(unsigned long long value)
{
	char	*str_value;
	char	*str;

	if (value)
	{
		str_value = ft_itoa_base_u(value, 16, "0123456789abcdef");
		str = ft_strjoin("0x", str_value);
		free(str_value);
	}
	else
		str = ft_init_null("(nil)");
	return (str);
}

void	ft_write_p(t_spec *spec)
{
	unsigned long long	ptr;
	char				*ptr_str;
	size_t				len_str;
	char				count_treat_minus;

	count_treat_minus = 0;
	ptr = va_arg(spec->ap, unsigned long long);
	ptr_str = ft_itoa_base_ptr(ptr);
	len_str = ft_strlen(ptr_str);
	if (spec->prec >= 0 && len_str > (size_t)spec->prec)
		len_str = spec->prec;
	count_treat_minus += ft_treat_minus(spec, 0, ptr_str, len_str);
	ft_treat_width(spec, spec->width, len_str, spec->zero);
	count_treat_minus += ft_treat_minus(spec, 1, ptr_str, len_str);
	free(ptr_str);
	if (count_treat_minus == 0)
		spec->error = 1;
	return ;
}
