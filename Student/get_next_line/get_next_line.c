/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:29:55 by tquere            #+#    #+#             */
/*   Updated: 2022/11/15 21:14:12 by zelinsta         ###   ########.fr       */
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

static char	*save(char *str, char *buffer, int i)
{
	if (str == NULL)
	{
		str = malloc(0);
		str[0] = '\0';
	}
	str = my_strncat(str, buffer, i + 1) ;
	ft_memmove(buffer, buffer + i + 1, BUFFER_SIZE - i);
	buffer[BUFFER_SIZE - i - 1] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 100];
	char			*str;
	int				bytes;
	int				i;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) == -1)
		return (NULL);
	str = NULL;
	buffer[BUFFER_SIZE] = '\0';
	
	//ANCIEN BUFFER
	i = 0;
	if (buffer[i])
	{	
		while (buffer[i] && buffer[i] != '\n')
			i++;
		if (buffer[i] == '\n')
			return (save(str, buffer, i));
		else
			str = save(str, buffer, i);
	}
	//NOUVEAUX BUFFER
	bytes = read (fd, buffer, BUFFER_SIZE);
	while (buffer[i] && bytes > 0)
	{	
		if (buffer[i] && buffer[i] == '\n')
			return (save(str, buffer, i));
		i++;
		if (i == bytes)
		{
			str = save(str, buffer, i - 1);
			bytes = read (fd, buffer, BUFFER_SIZE);
			i = 0;
		}
	}
	str = save(str, buffer, i);
	return (str);
}
// 				BUFFER CHANGEABLE ? SI OUI CHANGER LES /n
// 				OU FAIRE UNE COPIE CHANGEABLE

// static char	*buffer_loop(int fd, char g_buffer[])
// {
// 	char		*str;
// 	int			bytes;
// 	int			i;

// 	i = 0;
// 	bytes = read (fd, g_buffer, BUFFER_SIZE);
// 	while (g_buffer[i] && bytes > 0)
// 	{
// 		if (g_buffer[i] && g_buffer[i] == '\n')
// 		{
// 			str = save(str, g_buffer, i + 1, 0);
// 			return (str);
// 		}
// 		i++;
// 		if (i == bytes)
// 		{
// 			str = save(str, g_buffer, i, 0);
// 			bytes = read (fd, g_buffer, BUFFER_SIZE);
// 			i = 0;
// 		}
// 	}
// 	return (str);
// }

// char	*get_next_line(int fd)
// {
// 	static char			g_buffer[BUFFER_SIZE];
// 	char				*str;
// 	int					i;

// 	if (fd < 0 || BUFFER_SIZE < 1)
// 		return (NULL);
// 	str = NULL;
// 	i = 0;
// 	if (g_buffer[i] == '\n')
// 	{	
// 		i++;
// 		while (g_buffer[i] && g_buffer[i] != '\n')
// 			i++;
// 		if (g_buffer[i] == '\n')
// 		{
// 			str = save(str, g_buffer, i - 1, 1);
// 			return (str);
// 		}
// 		else
// 			str = save(str, g_buffer, i, 1);
// 	}
// 	str = buffer_loop(fd, g_buffer);
// 	return (str);
// }

