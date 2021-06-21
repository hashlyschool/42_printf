#include "includes/ft_printf.h"

#include <stdio.h>
#define MY_TEST " -%*c* -%-*c* ", -2, 0, 2, 0

int	main()
{
	setvbuf(stdout, NULL, _IONBF, 0);

	ft_printf("\n\noutput ft    : '");
	printf("'    out: %d", ft_printf(MY_TEST));
	ft_printf("\n\noutput origin: '");
	printf("'    out: %d",printf(MY_TEST));
	ft_printf("\n");

	//printf("===%d===", ft_strncmp(ft_printf(MY_TEST), printf(MY_TEST), 11));
	return (0);
}
