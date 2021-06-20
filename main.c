#include "includes/ft_printf.h"

#include <stdio.h>

int	main()
{
	printf("A: '");
	ft_printf("%c", '0');
	printf("' B: '");
	printf("%c", '0');
	printf("'");
	return (0);
}