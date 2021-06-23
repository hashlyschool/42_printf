#include "../includes/ft_printf.h"

static char	*ft_treat_prec(int prec, char *str, int len_str)
{
	char	*tmp;
	char	*new;
	int		i;
	int		j;
	char	minus;

	i = 0;
	j = 0;
	minus = 0;
	tmp = str;
	new = ft_calloc(prec + 1, sizeof(char));
	if (str[i] == '-')
	{
		new[i++] = '-';
		minus = 1;
		j++;
	}
	while (i - minus < prec - len_str)
		new[i++] = '0';
	while (tmp[j])
		new[i++] = tmp[j++];
	free(tmp);
	str = new;
	return (str);
}

void	ft_write_d_i(t_spec *spec)
{
	int		nbr;
	char	*nbr_str;
	size_t	len_str_nbr;
	char	count_treat_minus;

	count_treat_minus = 0;
	nbr = va_arg(spec->ap, int);
	nbr_str = ft_itoa(nbr);
	len_str_nbr = ft_strlen(nbr_str);
	if (nbr < 0)
		len_str_nbr--;
	if (/*spec->prec > (int)len_str_nbr && */spec->prec != -1)
		nbr_str = ft_treat_prec(spec->prec, nbr_str, len_str_nbr);
	len_str_nbr = ft_strlen(nbr_str);
	count_treat_minus += ft_treat_minus(spec, 0, nbr_str, len_str_nbr);
	ft_treat_width(spec, spec->width, len_str_nbr, spec->zero);
	count_treat_minus += ft_treat_minus(spec, 1, nbr_str, len_str_nbr);
	free(nbr_str);
	if (count_treat_minus == 0)
		spec->error = 1;
	return ;
}
