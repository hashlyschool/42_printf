#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *source, size_t count)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)source;
	if (s > d)
	{
		while (count--)
			*d++ = *s++;
	}
	else if (s < d)
	{
		while (count--)
			*(d + count) = *(s + count);
	}
	return (dest);
}
