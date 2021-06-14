#include "libft.h"

static size_t	ft_find_len(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;

	str_len = ft_strlen(s);
	if (len > str_len - start)
		return (str_len - start);
	if (start > str_len)
		return (0);
	else
		return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(*s) * (ft_find_len(s, start, len) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
