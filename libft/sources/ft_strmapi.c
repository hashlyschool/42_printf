#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*ptr;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	while (len--)
		ptr[len] = f(len, s[len]);
	return (ptr);
}
