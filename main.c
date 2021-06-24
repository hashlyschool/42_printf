#include "includes/ft_printf.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define UCHAR_MAX (__SCHAR_MAX__*2  +1)
#define USHRT_MAX (__SHRT_MAX__ *2  +1)
#define UINT_MAX  (__INT_MAX__  *2U +1U)
#define ULONG_MAX (__LONG_MAX__ *2UL+1UL)

#define MY_TEST " %-3.2u %10.42u ", 1, -1
int	main()
{
	setvbuf(stdout, NULL, _IONBF, 0);

	ft_printf("\n\noutput ft    : '");
	printf("'    out: %d", ft_printf(MY_TEST));
	ft_printf("\n\noutput origin: '");
	printf("'    out: %d",printf(MY_TEST));
	ft_printf("\n");

	return (0);
}
