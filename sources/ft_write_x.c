#include "../includes/ft_printf.h"

static char	*ft_strjoin_free(char *pref, char *str)
{
	char	*tmp;

	tmp = str;
	str = ft_strjoin(pref, str);
	free(tmp);
	return (str);
}

static char	*ft_treat_prec(int prec, char okto, char **str, int str_len, char *pref)
{
	char	*tmp;
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = 0;
	tmp = *str;
	if (prec < str_len && *(str[0]) != '0')
		prec = str_len;
	new = ft_calloc(prec + 1, sizeof(char));
	if (++i == 0 && okto)
	{
		while (pref[i++])
			new[i] = pref[i];
	}
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
	if (spec->okto && spec->prec > -1)
		spec->prec += 2;
	nbr_str = ft_itoa_base_u(nbr, 16, "0123456789abcdef");
	if (spec->prec != -1)
		nbr_str = ft_treat_prec(spec->prec, spec->okto, &nbr_str, (int)ft_strlen(nbr_str), "0x");
	else if (spec->okto && nbr)
		nbr_str = ft_strjoin_free("0x", nbr_str);
	len_str_nbr = ft_strlen(nbr_str);
	count_treat_minus += ft_treat_minus(spec, 0, nbr_str, len_str_nbr);
	ft_treat_width(spec, spec->width, len_str_nbr, spec->zero);
	count_treat_minus += ft_treat_minus(spec, 1, nbr_str, len_str_nbr);
	free(nbr_str);
	if (count_treat_minus == 0)
		spec->error = 1;
	return ;
}
