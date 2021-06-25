#include "includes/ft_printf.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MY_TEST "% 7d", 33

int	main()
{
	setvbuf(stdout, NULL, _IONBF, 0);

	printf("\n\noutput ft    : '");
	printf("'    out: %d", ft_printf(MY_TEST));
	printf("\n\noutput origin: '");
	printf("'    out: %d",printf(MY_TEST));
	printf("\n");

	return (0);
}
