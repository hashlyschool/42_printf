#include "../includes/ft_printf.h"

static void	ft_strjoin_free(t_spec	*spec, char *str, size_t len_str)
{
	char	*tmp;

	tmp = spec->final_str;
	spec->final_str = ft_strjoin_len(spec->final_str, str, spec->len, len_str);
	spec->len++;
	free(tmp);
	return ;
}

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

static void	ft_add_minus_space(t_spec *spec, char nbr_is_negativ, char mode)
{
	char	flag;
	char	minus_plus;

	flag = 0;
	if (spec->minus == 1 && spec->zero == 0 && mode == 0)
		flag = 1;
	else if (spec->minus == 0 && spec->zero == 1 && mode == 0)
		flag = 1;
	else if (spec->minus == 0 && spec->zero == 0 && mode == 1)
		flag = 1;
	if (spec->plus && !nbr_is_negativ)
	{
		minus_plus = '+';
		nbr_is_negativ = 1;
		spec->width--;
	}
	else
		minus_plus = '-';
	if (spec->space && !nbr_is_negativ)
		spec->width--;
	if (nbr_is_negativ && flag)
		ft_strjoin_free(spec, &minus_plus, 1);
	else if (spec->space && flag)
		ft_strjoin_free(spec, " ", 1);
	return ;
}

static long int	ft_abs_nbr(t_spec *spec, int nbr, char *flag)
{
	long int	nbr2;

	*flag = 0;
	nbr2 = nbr;
	if (nbr < 0)
	{
		*flag = 1;
		nbr2 = (long int)nbr * (long int)(-1);
		if (spec->width)
			spec->width--;
	}
	return (nbr2);
}

void	ft_write_d_i(t_spec *spec)
{
	long int	nbr;
	char		*nbr_str;
	size_t		len_str_nbr;
	char		count_treat_minus;
	char		flag;

	count_treat_minus = 0;
	nbr = va_arg(spec->ap, int);
	nbr = ft_abs_nbr(spec, nbr, &flag);
	ft_add_minus_space(spec, flag, 0);
	nbr_str = ft_itoa_base_u(nbr, 10, "0123456789");
	if (spec->prec != -1)
		nbr_str = ft_treat_prec(spec->prec, &nbr_str, (int)ft_strlen(nbr_str));
	len_str_nbr = ft_strlen(nbr_str);
	count_treat_minus += ft_treat_minus(spec, 0, nbr_str, len_str_nbr);
	ft_treat_width(spec, spec->width, len_str_nbr, spec->zero);
	ft_add_minus_space(spec, flag, 1);
	count_treat_minus += ft_treat_minus(spec, 1, nbr_str, len_str_nbr);
	free(nbr_str);
	if (count_treat_minus == 0)
		spec->error = 1;
	return ;
}
