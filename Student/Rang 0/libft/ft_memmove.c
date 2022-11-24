/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:08:15 by tquere            #+#    #+#             */
/*   Updated: 2022/11/19 20:29:53 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int			index;
	char		*from;
	char		*to;

	from = (char *) src;
	to = (char *) dst;
	if (from < to && (size_t)(to - from) < len)
	{
		index = len;
		while (index-- > 0)
			to[index] = from[index];
		return (dst);
	}
	ft_memcpy(dst, src, len);
	return (dst);
}
