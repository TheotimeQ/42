/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:29:57 by tquere            #+#    #+#             */
/*   Updated: 2022/11/16 19:27:59 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	index;

	if (s == NULL)
		return (0);
	index = 0;
	while (s[index])
		index++;
	return (index);
}

static char	*my_strncat(char *dest, char *src, size_t n)
{
	size_t	index_dest;
	size_t	index_src;
	char	*new_str;

	new_str = malloc((ft_strlen(dest) + n + 1) * sizeof(char));
	index_src = -1;
	index_dest = -1;
	while (dest[++index_dest])
		new_str[index_dest] = dest[index_dest];
	while (src[++index_src] && index_src < n)
		new_str[index_dest + index_src] = src[index_src];
	new_str[index_dest + index_src] = '\0';
	free(dest);
	return (new_str);
}

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
	while ((size_t)index < len)
	{
		to[index] = from[index];
		index++;
	}
	return (dst);
}

char	*save(char *str, char *buffer, int i)
{	
	if (str == NULL)
	{
		str = malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	str = my_strncat(str, buffer, i + 1) ;
	ft_memmove(buffer, buffer + i + 1, BUFFER_SIZE - i - 1);
	buffer[BUFFER_SIZE - i - 1] = '\0';
	return (str);
}