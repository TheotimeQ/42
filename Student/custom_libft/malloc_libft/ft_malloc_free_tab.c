/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_free_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:29:31 by tquere            #+#    #+#             */
/*   Updated: 2022/11/20 12:46:15 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	free_tab(void **tab)
{
	int	index;

	if (!tab)
		return ;
	index = 0;
	while (tab[index] != NULL)
	{
		free(tab[index]);
		index++;
	}
	free(tab);
}
