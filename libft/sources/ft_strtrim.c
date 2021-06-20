#include "../includes/libft.h"

static int	ft_check_char_set(char const c, char const *set)
{
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start;
	size_t	end;
	size_t	len_ptr;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_check_char_set(s1[start], set))
		start++;
	while (end > start && ft_check_char_set(s1[end - 1], set))
		end--;
	len_ptr = end - start;
	ptr = (char *)malloc(sizeof(*s1) * (len_ptr + 1));
	if (!ptr)
		return (NULL);
	while (start < end)
		*ptr++ = s1[start++];
	*ptr = 0;
	return (ptr - len_ptr);
}
