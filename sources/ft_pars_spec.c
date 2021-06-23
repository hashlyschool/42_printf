#include "../includes/ft_printf.h"

/*
	ptr - pointer to %+1
	Прогоняет до обязательного типа и выставляет его в структуру
	Если не нашел, то вызывает ошибку
	возвращает указатель на символ type
*/

static char	*check_type(char *ptr, t_spec *spec)
{
	char	chr;
	char	i;
	char	*ptr2;

	i = -1;
	while (*(spec->list_type + ++i))
	{
		chr = *(spec->list_type + i);
		ptr2 = ft_strchr(ptr, chr);
		if (ptr2)
		{
			spec->type = *ptr2;
			return (ptr2);
		}
	}
	spec->error = 1;
	return (ptr2);
}

/*
	Ищет флаги
	Если находит возвращает указатель на последний флаг + 1
	Иначе возвращает ptr - знак после %
*/

static char	*check_flags(char *ptr, char *ptr2, t_spec *spec, const char *l_fl)
{
	char	*end_flags;
	char	*flag;

	end_flags = ptr;
	while (ptr < ptr2 && *ptr != '.')
	{
		flag = NULL;
		if (*ptr > '0' && *ptr <= '9')
			return (end_flags);
		flag = ft_strchr(l_fl, *ptr);
		if (flag)
		{
			end_flags = ptr + 1;
			ft_set_flag(*flag, spec);
		}
		ptr++;
	}
	if (*ptr == '.')
		spec->prec = 0;
	return (end_flags);
}

/*
	ptr - указатель на символ после флага
	или после %, если флагов нет
	Ищет ширину и записывает её в spec, если не нашел записывает 0
	возвращает указатель на последний символ ширины + 1
	если ширины нет, то возвращвет ptr
*/

static char	*check_width(char *ptr, t_spec *spec)
{
	char	*start;
	char	*end;

	if (*ptr > '0' && *ptr <= '9')
	{
		start = ptr;
		while (*ptr >= '0' && *ptr <= '9')
			ptr++;
		end = ptr;
		spec->width = ft_atoi(start);
		return (end);
	}
	else if (*ptr == '*')
	{
		spec->width_star = 1;
		return (ptr + 1);
	}
	return (ptr);
}

/*
	ptr указатель на точку или нет.
	возвращает указатель на след символ после точности
	Если точности нет то возвращает ptr
*/

static char	*check_prec(char *ptr, t_spec *spec)
{
	if (*ptr == '.')
	{
		ptr++;
		if (*ptr == '*')
		{
			spec->prec_star = 1;
			return (ptr + 1);
		}
		spec->prec = ft_atoi(ptr);
		while (*ptr >= '0' && *ptr <= '9')
			ptr++;
		return (ptr + 1);
	}
	return (ptr);
}

/*
	ptr - указатель на символ после %
	проверяет на /0 and error, парсит спецификатор
	записывает в spec параметры
	возвращает указатель на конец спецификатора + 1
*/

char	*ft_parse_spec(char *ptr, t_spec *spec)
{
	char	*ptr2;

	if (!(*ptr) || spec->error)
		return (ptr);
	ptr2 = check_type(ptr, spec);
	if (ptr2 == ptr)
		return (ptr2 + 1);
	if (spec->error)
		return (ptr2);
	ptr = check_flags(ptr, ptr2, spec, "-0# +");
	ptr = check_width(ptr, spec);
	ptr = check_prec(ptr, spec);
	ptr = ft_check_size(ptr, spec);
	return (ptr2 + 1);
}
