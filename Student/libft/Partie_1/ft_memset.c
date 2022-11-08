/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:34:35 by tquere            #+#    #+#             */
/*   Updated: 2022/11/08 14:46:45 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		index;

	index = 0;
	while (((char *) b)[index] && index < len)
	{
		((char *) b)[index] = c;
		index++;
	}
	return (b);
}
