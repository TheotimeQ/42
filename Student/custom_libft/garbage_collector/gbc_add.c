#include "../libft.h"

static t_list	*ft_gdb_new(void *content)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (new_elem == NULL)
		return (NULL);

    //Mettre l'adresse du pointeur ?
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}

void	ft_gdb_add_front(t_list **lst, t_list *new)
{	
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

void gbc_add(void *content, t_gbc *gbc)
{   
    t_list *new_garbage;

    new_garbage = ft_gdb_new(content);



    free(gbc);
}