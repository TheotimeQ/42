/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:39:11 by tquere            #+#    #+#             */
/*   Updated: 2022/11/22 10:12:51 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*loop_read(char *buffer, int fd, char *str)
{	
	int				bytes;
	int				i;

	i = 0;
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes == 0)
		return (str);
	while (buffer[i] && bytes > 0)
	{	
		if (buffer[i] && buffer[i] == '\n')
			return (save(str, buffer, i));
		i++;
		if (i == bytes)
		{
			str = save(str, buffer, i - 1);
			bytes = read(fd, buffer, BUFFER_SIZE);
			i = 0;
		}
		if (!buffer[i])
			break ;
	}
	str = save(str, buffer, i);
	return (str);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*str;
	int				i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (read(fd, buffer, 0) == -1)
	{
		ft_memset(buffer, '\0', BUFFER_SIZE);
		return (NULL);
	}
	str = NULL;
	buffer[BUFFER_SIZE] = '\0';
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
	str = loop_read(buffer, fd, str);
	return (str);
}
