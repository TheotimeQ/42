/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:34:41 by tquere            #+#    #+#             */
/*   Updated: 2022/11/27 16:48:34 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int				i;
	int				j;
	size_t			dest_size;
	size_t			src_size;

	if (dst == NULL && dstsize == 0)
		return (0);
	dest_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	i = 0;
	if (dstsize < dest_size)
		return (dstsize + src_size);
	while (dst[i] && dstsize-- > 0)
		i++;
	j = 0;
	while (src[j] && dstsize > 1)
	{
		dst[i + j] = src[j];
		dstsize--;
		j++;
	}
	if (dstsize > 0)
		dst[i + j] = '\0';
	return (dest_size + src_size);
}
