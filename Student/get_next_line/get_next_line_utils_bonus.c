/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:40:36 by tquere            #+#    #+#             */
/*   Updated: 2022/11/17 17:40:38 by tquere           ###   ########.fr       */
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
	if (new_str == NULL)
		return (NULL);
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
	index = 0;
	while ((size_t)index < len)
	{
		to[index] = from[index];
		index++;
	}
	return (dst);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		index;
	char		*str;

	str = b;
	index = 0;
	while (index < len)
	{
		str[index] = (unsigned char)c;
		index++;
	}
	return (b);
}

char	*save(char *str, char *buffer, int i)
{	
	if (str == NULL)
	{
		str = malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	str = my_strncat(str, buffer, i + 1);
	if (str == NULL)
		return (NULL);
	ft_memmove(buffer, buffer + i + 1, BUFFER_SIZE - i - 1);
	ft_memset(buffer + BUFFER_SIZE - i - 1, '\0', i + 1);
	return (str);
}
