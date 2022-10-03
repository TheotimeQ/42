/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 08:10:43 by tquere            #+#    #+#             */
/*   Updated: 2022/07/28 11:26:36 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*remaloc(int len, char *str)
{	
	char	*temp_line;

	temp_line = ft_strncpy(malloc(sizeof(char *) * len), str, len);
	free(str);
	return (temp_line);
}

void	got_to_end_and_print_2(char *str, int nb_from_end, int len)
{
	int					index;

	index = 0;
	while (str[index] && index < len - nb_from_end)
	{	
		index++;
	}
	while (str[index] && index < len)
	{
		write(1, &str[index], 1);
		index++;
	}
}

void	open_stdin_2(int nb_from_end)
{	
	int			file;
	char		buffer[3];
	char		*str;
	int			malloc_len;
	int			count_char;

	malloc_len = 100;
	count_char = 0;
	str = malloc(sizeof(char) * malloc_len);
	file = open(STDIN_FILENO, O_RDWR);
	while (read(STDIN_FILENO, buffer, 1) > 0)
	{	
		str[++count_char] = buffer[0];
		if (count_char > malloc_len)
		{
			malloc_len += 100;
			str = remaloc(malloc_len, str);
		}
	}
	str[++count_char] = '\0';
	close(file);
	got_to_end_and_print_2(str, nb_from_end, count_char);
}
