/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gbc_show.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:13:05 by tquere            #+#    #+#             */
/*   Updated: 2022/11/20 15:02:32 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	show_gbc_list(t_list *lst)
{	
	if (lst == NULL)
		return ;
	if (lst->content)
		write(1, "GARBAGE\n", 8);
	else
		write(1, "EMPTY  \n", 8);
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (lst->content)
			write(1, "GARBAGE\n", 8);
		else
			write(1, "EMPTY  \n", 8);
	}
	return ;
}

void	gbc_show(t_gbc *gbc)
{
	write(1, "\n-------SHOW GBC-------\n", 24);
	if (!gbc)
	{
		write(1, "No gbc\n", 7);
		return ;
	}
	if (!gbc->malloc_error)
		write(1, "  - MALLOC ERROR : 0\n", 21);
	else
		write(1, "  - MALLOC ERROR : 1\n", 21);
	if (gbc->gb_list)
		show_gbc_list(*(gbc->gb_list));
	else
		write(1, "  - NO GARBAGE \n", 16);
	write(1, "----------------------\n", 22);
}
