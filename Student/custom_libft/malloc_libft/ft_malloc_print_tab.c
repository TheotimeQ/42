/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_print_tab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:48:17 by tquere            #+#    #+#             */
/*   Updated: 2022/11/20 12:49:06 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_malloc_print_tab(char **tab)
{
	int	index;

	if (!tab)
		return ;
	index = 0;
	while (tab[index] != NULL)
	{
		write(1, "|", 1);
		ft_putstr_fd(tab[index], 1);
		write(1, "|\n", 2);
		index++;
	}
}
