#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int ch, size_t count)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)source;
	while (count--)
	{
		*d++ = *s++;
		if (*(d - 1) == (unsigned char)(ch))
			return (d);
	}
	return (NULL);
}
