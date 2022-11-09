
#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
    t_list	*new_list;
    t_list  *elem;

    if (!lst || !f)
        return (NULL);

    if ((elem = ft_lstnew(f(lst->content))) == NULL)
    {
        ft_lstclear(&new_list, del);
        return (NULL);
    }
	new_list = elem;
	lst = lst->next;
    while (lst != NULL)
	{
		if ((elem = ft_lstnew(f(lst->content))) == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&new_list, elem);
	}
    return (new_list);
}
