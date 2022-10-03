/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 06:15:19 by tquere            #+#    #+#             */
/*   Updated: 2022/07/20 06:15:20 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int		index;
	int		*int_tab;

	int_tab = malloc(sizeof(int) * length);
	index = 0;
	while (index < length)
	{
		int_tab[index] = (*f)(tab[index]);
		index++;
	}
	return (int_tab);
}
