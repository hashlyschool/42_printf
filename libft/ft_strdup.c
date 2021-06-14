#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*ptr;

	len = ft_strlen(src);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == (void *)0)
		return ((void *)0);
	ft_strlcpy(ptr, src, len + 1);
	return (ptr);
}
