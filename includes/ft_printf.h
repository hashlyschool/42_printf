#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"

typedef struct s_spec
{
	va_list	ap;
	char	*final_str;
	char	minus;
	char	zero;
	char	okto;
	char	space;
	char	plus;
	int		width;
	char	width_star;
	int		prec;
	char	prec_star;
	char	size[2];
	char	type;
	char	*list_type;
	char	error;
	int		len;
}				t_spec;

/*main*/
int		ft_printf(const char *str, ...);
/*parser*/
char	*ft_parse_spec(char *ptr, t_spec *spec);
char	*ft_check_size(char *ptr, t_spec *spec);
/*write arguments*/
void	ft_write_arg(t_spec *spec);
void	ft_write_c(t_spec *spec);
void	ft_write_s(t_spec *spec);
void	ft_write_p(t_spec *spec);
void	ft_write_d_i(t_spec *spec);
void	ft_write_u(t_spec *spec);
void	ft_write_x(t_spec *spec);
void	ft_write_X(t_spec *spec);
void	ft_write_pers(t_spec *spec);
/*secondary functions*/
char	*ft_strjoin_len(char *s1, char *s2, size_t len1, size_t len2);
void	ft_set_flag(char flag, t_spec *spec);
/*treat flags*/
void	ft_treat_width(t_spec *spec, int width, int len_str, int zero);
char	ft_treat_minus(t_spec *spec, char mode, char *c, size_t len_c);

#endif
