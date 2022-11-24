/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gbc_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:04:23 by tquere            #+#    #+#             */
/*   Updated: 2022/11/22 09:11:11 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//Stocker le pointeur 
static t_list	*ft_gdb_new(void *content)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (new_elem == NULL)
		return (NULL);
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}

static void	gbc_ft_lstadd_front(t_list **lst, t_list *new)
{	
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

void	gbc_add(void *content, t_gbc *gbc)
{
	t_list	*new_garbage;

	new_garbage = ft_gdb_new(content);
	if (new_garbage == NULL)
	{
		gbc->malloc_error = 1;
		return ;
	}
	gbc_ft_lstadd_front(gbc->gbc_list, new_garbage);
}
