/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gbc_all_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:13:25 by tquere            #+#    #+#             */
/*   Updated: 2022/11/22 09:11:11 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	gbc_ft_lstclear(t_list **lst)
{
	t_list	*tmp;
	t_list	*elem;

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
	gbc_ft_lstclear(gbc->gbc_list);
}
