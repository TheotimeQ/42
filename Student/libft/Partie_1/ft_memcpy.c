/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:34:30 by tquere            #+#    #+#             */
/*   Updated: 2022/11/08 15:34:35 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{	
	size_t		index;

	index = 0;
	while (index < n)
	{
		((char *)dst)[index] = ((char *)src)[index];
		index++;
	}
	return (dst);
}
