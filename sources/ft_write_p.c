#include "../includes/ft_printf.h"

static char	*ft_init_null()
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 7 + 1);
	ft_memcpy(str, "(nil)", 7);
	return (str);
}

static char	*ft_itoa_base_ptr(unsigned long long value, int base)
{
	char					*str;
	int						size;
	char					*tab;
	unsigned long long		tmp;
	char					pref;

	size = 0;
	pref = 0;
	tab = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (0);
	tmp = value;
	while (tmp /= base)
		size++;
	if (base == 16 && value)
		pref = 2;
	if (base == 8 && value)
		pref = 1;
	size = size + pref + 1;
	if (value)
		str = (char *)malloc(sizeof(char) * size  + 1);
	else
	{
		str = ft_init_null();
		return str;
	}
	str[size] = '\0';
	while (size > pref)
	{
		str[size-- - 1] = tab[value % base];
		value /= base;
	}
	if (pref == 2)
	{
		str[0] = '0';
		str[1] = 'x';
	}
	if (pref == 1)
		str[0] = '0';
	return (str);
}

void		ft_write_p(t_spec *spec)
{
	unsigned long long	ptr;
	char				*ptr_str;
	char				*new_str;
	size_t				len_c;

	ptr = va_arg(spec->ap, unsigned long long);
	ptr_str = ft_itoa_base_ptr(ptr, 16);
	len_c = ft_strlen(ptr_str);
	if (spec->prec >= 0 && len_c > (size_t)spec->prec)
		len_c = spec->prec;
	if (spec->minus)
	{
		new_str = ft_strjoin_len(spec->final_str, ptr_str, spec->len, len_c);
		spec->len += len_c;
		free(spec->final_str);
		spec->final_str = new_str;
	}
	ft_treat_width(spec, spec->width, len_c, spec->zero);
	if (!spec->minus)
	{
		new_str = ft_strjoin_len(spec->final_str, ptr_str, spec->len, len_c);
		spec->len += len_c;
		free(spec->final_str);
		spec->final_str = new_str;
	}
	free(ptr_str);
	if (!new_str)
		spec->error = 1;
	return ;
}
