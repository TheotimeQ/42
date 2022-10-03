/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dico.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 12:09:58 by tquere            #+#    #+#             */
/*   Updated: 2022/07/24 12:28:51 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

t_dict		init_dict(void);

char		*ft_strncpy(char *dest, char *src, unsigned int n);
char		*ft_strncat(char *dest, char *src, unsigned int nb);
t_dict		sort_in_dict(t_dict dict, char *value, char *key);
t_dict		split_and_sort(char *str, t_dict dict);
char		*init_str(char *str, int len);

char	*create_str(int str_len)
{
	char	*str;

	str = malloc(sizeof(char) * str_len + 1);
	str = init_str(str, str_len);
	return (str);
}

char	*remalloc(char *str, int str_len)
{
	char	*new_str;

	new_str = malloc(sizeof(char) * (str_len + 1));
	new_str = init_str(new_str, str_len);
	new_str = ft_strncpy(new_str, str, str_len - 1);
	free(str);
	return (new_str);
}

t_dict	loop_on_line(t_dict dict, int str_len, char *new_line, int file)
{
	int			count_char;
	char		buffer[2];

	while (read(file, buffer, 1) > 0 && dict.error == 0)
	{
		if (count_char > str_len)
		{
			str_len += 1 ;
			count_char = str_len;
			new_line = remalloc(new_line, str_len);
		}
		new_line = ft_strncat(new_line, buffer, 1);
		if (buffer[0] == '\n' || buffer[0] == EOF)
		{
			dict = split_and_sort(new_line, dict);
			new_line = init_str(new_line, str_len);
			count_char = 0;
		}
		count_char++;
	}
	return (dict);
}

t_dict	ini_dict(t_dict dict)
{	
	int	index;

	dict.zero_twenty = malloc(sizeof(char *) * 21);
	dict.twenty_hundred = malloc(sizeof(char *) * 21);
	dict.ten_power = malloc(sizeof(char *) * 21);
	index = 0;
	while (index <= 20)
	{
		dict.zero_twenty[index] = "\0";
		dict.twenty_hundred[index] = "\0";
		dict.ten_power[index] = "\0";
		index++;
	}
	dict.max_power = 0;
	dict.error = 0;
	return (dict);
}

t_dict	read_dict(t_input input)
{
	t_dict		dict;
	int			file;
	char		*new_line;
	int			str_len;

	dict.error = 0;
	dict.value = malloc(1);
	dict.key = malloc(1);
	dict = ini_dict(dict);
	file = open(input.file, O_RDWR);
	if (file == -1)
	{
		dict.error = 1;
		return (dict);
	}
	str_len = 20;
	new_line = create_str(str_len);
	dict = loop_on_line(dict, str_len, new_line, file);
	close(file);
	return (dict);
}
