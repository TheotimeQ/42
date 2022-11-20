/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:07:57 by tquere            #+#    #+#             */
/*   Updated: 2022/11/20 16:01:47 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
