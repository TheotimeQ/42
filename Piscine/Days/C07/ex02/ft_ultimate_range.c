/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:11:43 by tquere            #+#    #+#             */
/*   Updated: 2022/07/28 04:42:15 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	size_range(int **range)
{	
	int	index;

	index = 0;
	while (range[index])
	{
		index++;
	}
	return (index);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	index;

	if (min >= max)
	{	
		*range = NULL;
		return (0);
	}
	index = 0;
	*range = malloc(sizeof(int) * (max - min));
	if ((*range) == 0)
		return (-1);
	while (index < max - min)
	{
		(*range)[index] = min + index;
		index++;
	}
	return (max - min);
}
