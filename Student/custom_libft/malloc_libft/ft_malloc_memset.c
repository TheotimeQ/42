/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_memset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:45:30 by tquere            #+#    #+#             */
/*   Updated: 2022/11/20 12:46:49 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_malloc_memset(void *b, int c, size_t len)
{
	size_t		index;
	char		*str;

	if (!b)
		return (b);
	str = b;
	index = 0;
	while (index < len)
		str[index++] = (unsigned char)c;
	return (b);
}
