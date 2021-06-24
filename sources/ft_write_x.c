#include "../includes/ft_printf.h"

static char	*ft_treat_prec(int prec, char **str, int str_len)
{
	char	*tmp;
	char	*new;
	int		i;
	int		j;

	i = 0;
	tmp = *str;
	if (prec < str_len && *(str[0]) != '0')
		prec = str_len;
	new = ft_calloc(prec + 1, sizeof(char));
	j = i;
	while (i - j < prec - str_len)
		new[i++] = '0';
	while (i < prec)
		new[i++] = tmp[j++];
	free(tmp);
	*str = new;
	return (*str);
}

void	ft_write_x(t_spec *spec)
{
	unsigned int	nbr;
	char			*nbr_str;
	size_t			len_str_nbr;
	char			count_treat_minus;

	count_treat_minus = 0;
	nbr = va_arg(spec->ap, unsigned int);
	nbr_str = ft_itoa_base_u(nbr, 16, "0123456789abcdef");
	if (spec->prec != -1)
		nbr_str = ft_treat_prec(spec->prec, &nbr_str, (int)ft_strlen(nbr_str));
	len_str_nbr = ft_strlen(nbr_str);
	count_treat_minus += ft_treat_minus(spec, 0, nbr_str, len_str_nbr);
	ft_treat_width(spec, spec->width, len_str_nbr, spec->zero);
	count_treat_minus += ft_treat_minus(spec, 1, nbr_str, len_str_nbr);
	free(nbr_str);
	if (count_treat_minus == 0)
		spec->error = 1;
	return ;
}
