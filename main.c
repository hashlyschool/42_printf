#include "includes/ft_printf.h"

#include <stdio.h>

int	main()
{
	ft_printf("fds '%0-3c' 2 str: '%-.4c'\n", 't', 'a');
	printf("\nfds '%0-3c' 2 str: '%-.4c'\n", 't', 'a');
	return (0);
}