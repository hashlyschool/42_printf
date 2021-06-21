#include "includes/ft_printf.h"

#include <stdio.h>

int	main()
{
	setvbuf(stdout, NULL, _IONBF, 0);

	printf("\n\noutput ft: '");
	ft_printf("%10c", '0');
	ft_printf("'\n\noutput origin: '");
	printf("%10c", '0');
	printf("'\n");

	return (0);
}
