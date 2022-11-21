/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gbc_show.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:13:05 by tquere            #+#    #+#             */
/*   Updated: 2022/11/21 16:24:24 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//Ajouter fonction qui compte le nombre de free

static int	my_ft_lstsize(gb_list *lst)
{
	int		index;

	if (lst == NULL)
		return (0);
	index = 1;
	while (lst->next != NULL)
	{	
		lst = lst->next;
		index++;
	}
	return (index);
}

void	gbc_show(t_gbc *gbc)
{	
	char 	*size;
	
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
	{
		write(1, "  - GARBAGE : ", 14);
		size = ft_itoa(my_ft_lstsize(*(gbc->gb_list)));
		write(1, size, ft_strlen(size));
		write(1, "\n", 1);
		free(size);
	}
	else
		write(1, "  - NO GARBAGE \n", 16);
	write(1, "----------------------\n", 23);
}
