#include "libft.h"

void	*ft_memchr (const void *arr, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)(arr) == (unsigned char)c)
			return ((char *)(arr));
		arr++;
	}
	return (NULL);
}
