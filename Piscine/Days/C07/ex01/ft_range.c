/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:56:45 by tquere            #+#    #+#             */
/*   Updated: 2022/07/28 17:28:46 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int				*ptr;
	long int		size;
	long int		i;

	i = -1;
	ptr = NULL;
	if (min >= max)
		return (ptr);
	size = max - min;
	ptr = malloc (sizeof(int) * size);
	if (ptr == 0)
		return (NULL);
	while (++i < size)
		ptr[i] = min + i;
	return (ptr);
}
