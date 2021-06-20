#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (lst)
	{
		while (*lst)
		{
			ptr = (*lst)->next;
			del((*lst)->content);
			free(*lst);
			*lst = ptr;
		}
	}
	return ;
}
