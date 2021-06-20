#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc(sizeof(*s1) * (len + 1));
	if (!ptr)
		return (NULL);
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = 0;
	return (ptr - len);
}
