/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gbc_all_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:13:25 by tquere            #+#    #+#             */
/*   Updated: 2022/11/20 15:30:13 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	gbc_del(void *content)
{
	free(content);
}

static void	gbc_ft_lstdelone(t_list *lst, void (*del)(void*))
{	
	if (!lst || !del)
		return ;
	(*del)(lst->content);
	free(lst);
}

static void	gbc_ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{	
		printf("P1 : %p ", (*lst));
		tmp = (*lst)->next;
		gbc_ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	lst = NULL;
}

void	gbc_all_clear(t_gbc *gbc)
{
	gbc_ft_lstclear(gbc->gb_list, &gbc_del);
	free(gbc);
}
