/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:34:33 by tquere            #+#    #+#             */
/*   Updated: 2022/11/10 14:53:13 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	if (to < from && (size_t)(from - to) < len)
	{
		index = -1;
		while (index++ < (int)len - 1)
			to[index] = from[index];
		return (dst);
	}
	ft_memcpy(dst, src, len);
	return (dst);
}
