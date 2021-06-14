#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	n;

	if (!src)
		return (0);
	len = ft_strlen(src);
	if (!dst || !size)
		return (len);
	if (size)
	{
		if (len < size)
			n = len;
		else
			n = size - 1;
		while (n--)
			*dst++ = *src++;
		*dst = 0;
	}
	return (len);
}
