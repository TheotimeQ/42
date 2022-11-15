/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:29:55 by tquere            #+#    #+#             */
/*   Updated: 2022/11/15 18:46:44 by tquere           ###   ########.fr       */
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

static char	*my_strncat(char *dest, char *src, size_t n, size_t start)
{
	size_t	index_dest;
	size_t	index_src;
	char	*new_str;

	new_str = malloc((ft_strlen(dest) + n + 1) * sizeof(char));
	index_src = -1;
	index_dest = -1;
	while (dest[++index_dest])
		new_str[index_dest] = dest[index_dest];
	while (src[++index_src + start] && index_src + start < n)
		new_str[index_dest + index_src] = src[index_src + start];
	new_str[index_dest + index_src] = '\0';
	free(dest);
	return (new_str);
}

static char	*save(char *str, char *buffer, int i, int start)
{
	if (str == NULL)
	{
		str = malloc(0);
		str[0] = '\0';
	}
	str = my_strncat(str, buffer, i, start);
	return (str);
}

char	*get_next_line(int fd)
{
	static char			buffer[BUFFER_SIZE];
	char				*str;
	int					bytes;
	int					i;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) == -1)
		return (NULL);
	str = NULL;
	//ANCIEN BUFFER
	i = 0;
	if (buffer[i] == '\n')
	{	
		i++;
		if (!buffer[i])
			return (NULL);
		while (buffer[i] && buffer[i] != '\n')
			i++;
		if (buffer[i] == '\n')
			return (save(str, buffer, i - 1, 1));
		else
			str = save(str, buffer, i - 1, 1);
	}
	//NOUVEAUX BUFFER
	i = 0;
	bytes = read (fd, buffer, BUFFER_SIZE);
	while (buffer[i] && bytes > 0)
	{	
		if (buffer[i] && buffer[i] == '\n')
		{
			str = save(str, buffer, i + 1, 0);
			return (str);
		}
		i++;
		if (i == bytes)
		{
			str = save(str, buffer, i, 0);
			bytes = read (fd, buffer, BUFFER_SIZE);
			i = 0;
		}
	}
	return (str);
}
				BUFFER CHANGEABLE ? SI OUI CHANGER LES /n
				OU FAIRE UNE COPIE CHANGEABLE

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

