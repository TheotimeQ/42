/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gbc_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:13:34 by tquere            #+#    #+#             */
/*   Updated: 2022/11/21 16:57:46 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//Stocker le pointeur 
static gb_list	*ft_gdb_new(void *content)
{
	gb_list	*new_elem;

	new_elem = malloc(sizeof(gb_list));
	if (new_elem == NULL)
		return (NULL);
	new_elem->content = content;
	// new_elem->ptr_content = ptr_mem;
	new_elem->next = NULL;
	// printf("saved str= %p\n", new_elem->content);
	// printf("saved str %p\n", *(new_elem->ptr_content));
	// printf("saved &str %p\n\n", (new_elem->ptr_content));
	return (new_elem);
}

static void	gbc_ft_lstadd_front(gb_list **lst, gb_list *new)
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
	gb_list	*new_garbage;

	new_garbage = ft_gdb_new(content);
	if (new_garbage == NULL)
	{
		gbc->malloc_error = 1;
		return ;
	}
	gbc_ft_lstadd_front(gbc->gb_list, new_garbage);
}
