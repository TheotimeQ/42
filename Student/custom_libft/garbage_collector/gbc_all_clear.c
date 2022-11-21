/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gbc_all_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:13:25 by tquere            #+#    #+#             */
/*   Updated: 2022/11/21 17:07:49 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//Faire un fonction qui clear les liste avec un pointeur null

static void	gbc_ft_lstclear(gb_list **lst)
{
	gb_list	*tmp;
	gb_list *elem;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{	
		tmp = (*lst)->next;
		elem = *lst;
		free(elem->content);
		free(elem);
		*lst = tmp;
	}
	lst = NULL;
}

void	gbc_all_clear(t_gbc *gbc)
{
	gbc_ft_lstclear(gbc->gb_list);
}
