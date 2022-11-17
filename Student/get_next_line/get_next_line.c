/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:29:55 by tquere            #+#    #+#             */
/*   Updated: 2022/11/17 08:57:24 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*loop_read(char *buffer,int fd, char *str)
{	
	int				bytes;
	int				i;
	
	i = 0;
	bytes = read (fd, buffer, BUFFER_SIZE);
	if (!buffer[i])
		return (NULL);
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
			break;
	}
	str = save(str, buffer, i);
	return (str);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	char			*str;
	int				i;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) == -1)
		return (NULL);
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













// static void	last_read(char *buffer, char *str)
// {
// 	int				i;

// 	i = 0;
// 	if (buffer[i])
// 	{	
// 		while (buffer[i] && buffer[i] != '\n')
// 			i++;
// 		if (buffer[i] == '\n')
// 			return (save(str, buffer, i));
// 		else
// 			str = save(str, buffer, i);
// 	}
// 	return (str);
// }

// char	*get_next_line(int fd)
// {
// 	static char		buffer[BUFFER_SIZE];
// 	char			*str;
// 	int				i;
// 	// int				bytes;

// 	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) == -1)
// 		return (NULL);
// 	str = NULL;
// 	buffer[BUFFER_SIZE] = '\0';
	
// 	i = 0;
// 	if (buffer[i])
// 	{	
// 		while (buffer[i] && buffer[i] != '\n')
// 			i++;
// 		if (buffer[i] == '\n')
// 			return (save(str, buffer, i));
// 		else
// 			str = save(str, buffer, i);
// 	}

	// last_read(buffer, str);

	// i = 0;
	// bytes = read(fd, buffer, BUFFER_SIZE);
	// if (!buffer[i])
	// 	return (NULL);

	// while (buffer[i] && bytes > 0)
	// {	
	// 	if (buffer[i] && buffer[i] == '\n')
	// 		return (save(str, buffer, i));
	// 	i++;
	// 	if (i == bytes)
	// 	{
	// 		str = save(str, buffer, i - 1);
	// 		bytes = read(fd, buffer, BUFFER_SIZE);
	// 		i = 0;
	// 	}
	// 	if (!buffer[i])
	// 		break;
	// }
	// str = save(str, buffer, i);

// 	str = loop_read(buffer, fd, str);

// 	return (str); 4096
// }