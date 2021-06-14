#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (size <= len_dst)
		return (size + len_src);
	return (ft_strlcpy(dst + len_dst, src, size - len_dst) + len_dst);
}
