#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t count)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)buf;
	while (count--)
		*(unsigned char *)ptr++ = (unsigned char)ch;
	return (buf);
}
