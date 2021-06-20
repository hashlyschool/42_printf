#include "../includes/libft.h"

static size_t	ft_find_q_word(char const *s, char c)
{
	size_t	q_word;

	q_word = 0;
	while (*s == c && *s)
		s++;
	while (*s)
	{
		q_word++;
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
	}
	return (q_word);
}

static void	ft_free_mem(char **ptr, size_t len)
{
	while (len--)
		free(*ptr++);
	free(ptr);
	return ;
}

static size_t	ft_strlenc(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s++)
		len++;
	return (len);
}

static char	*ft_skip_c(char const *s, char c)
{
	while (*s == c && *s)
		s++;
	return ((char *)s);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	q_word;
	size_t	i;
	char	*start;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	q_word = ft_find_q_word(s, c);
	ptr = (char **)malloc(sizeof(char *) * (q_word + 1));
	if (!ptr)
		return (NULL);
	start = (char *)s;
	while (q_word--)
	{
		start = ft_skip_c(start, c);
		len = ft_strlenc(start, c);
		ptr[i] = ft_substr(s, start - s, len);
		if (!ptr[i++])
			ft_free_mem(ptr, q_word);
		start = start + len;
	}
	ptr[i] = NULL;
	return (ptr);
}
