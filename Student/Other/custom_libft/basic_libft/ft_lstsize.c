/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:02:32 by tquere            #+#    #+#             */
/*   Updated: 2022/11/22 09:02:32 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstsize(t_list *lst)
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