#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"

typedef	struct		s_spec
{
	//arg
	va_list	ap;
	//final str
	char	*final_str;
	//flags
	char	minus;
	char	zero;
		//bonus_flags
	char	okto;
	char	space;
	char	plus;
	//width
	int		width;
	//prec
	char	star;
	int		prec;
	//type
	//bonus_type
	char	size[2]; //l ll h hh
	char	type;
	char	*list_type;
	//error
	char	error;
}					t_spec;

//main
int		ft_printf (const char *, ...);
//parser
char	*ft_parse_spec(char *ptr, t_spec *spec);
char	*ft_check_size(char *ptr, t_spec *spec);
//write arguments
void	ft_write_arg(t_spec *spec);
void	ft_write_c(t_spec *spec);

//treat flags
void	ft_treat_width(t_spec *spec, int width, int minus, int zero);

#endif