#include "../includes/ft_printf.h"

static char	*ft_treat_prec(int prec, char okto, char **str, int str_len, char *pref)
{
	char	*tmp;
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = 0;
	tmp = *str;
	if (prec < str_len + 2 * okto && *(str[0]) != '0')
		prec = str_len + 2 * okto;
	new = ft_calloc(prec + 1, sizeof(char));
	if (okto)
	{
		while (pref[++i])
			new[i] = pref[i];
	}
	else
		++i;
	while (i - j < prec - str_len)
		new[i++] = '0';
	while (i < prec)
		new[i++] = tmp[j++];
	free(tmp);
	*str = new;
	return (*str);
}

static char	*ft_strjoin_free(char *pref, char *str)
{
	char	*tmp;

	tmp = str;
	str = ft_strjoin(pref, str);
	free(tmp);
	return (str);
}

static void	ft_treat_okto(t_spec *spec, int len_str_nbr, unsigned int nbr)
{
	char	*tmp;

	if (spec->okto)
	{
		if (nbr && spec->width - len_str_nbr > -2 && spec->zero)
		{
			tmp = spec->final_str;
			spec->final_str = ft_strjoin_len(spec->final_str, "0X", spec->len, 2);
			spec->len += 2;
			spec->width -= 2;
			free(tmp);
		}
	}
}

void	ft_write_X(t_spec *spec)
{
	unsigned int	nbr;
	char			*nbr_str;
	size_t			len_str_nbr;
	char			count_treat_minus;

	count_treat_minus = 0;
	nbr = va_arg(spec->ap, unsigned int);
	if (!nbr)
		spec->okto = 0;
	if (spec->okto && spec->prec > -1)
		spec->prec += 2;
	nbr_str = ft_itoa_base_u(nbr, 16, "0123456789ABCDEF");
	if (spec->prec != -1)
		nbr_str = ft_treat_prec(spec->prec, spec->okto, &nbr_str, (int)ft_strlen(nbr_str), "0X");
	else if (spec->okto && nbr && !(spec->width - (int)ft_strlen(nbr_str) > -2 && spec->zero))
		nbr_str = ft_strjoin_free("0X", nbr_str);
	len_str_nbr = ft_strlen(nbr_str);
	count_treat_minus += ft_treat_minus(spec, 0, nbr_str, len_str_nbr);
	ft_treat_okto(spec, len_str_nbr, nbr);
	ft_treat_width(spec, spec->width, len_str_nbr, spec->zero);
	count_treat_minus += ft_treat_minus(spec, 1, nbr_str, len_str_nbr);
	free(nbr_str);
	if (count_treat_minus == 0)
		spec->error = 1;
	return ;
}
