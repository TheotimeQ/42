/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcts_struct_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:34:10 by tquere            #+#    #+#             */
/*   Updated: 2022/07/28 15:12:18 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char			*ft_strncat(char *dest, char *src, unsigned int nb);
int				convert_str_int(char *str);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
char			*create_line(t_map_var *map);
char			*remaloc(t_map_var map, int cnt_char, char *new_line);
t_map_var		check_map_args(t_map_var map);
t_map_var		check_error_len_map(t_map_var map, int crt_lin);
t_map_var		save_line(t_map_var map, int cnt_char, char *new_line);

t_map_var	get_number(t_map_var map, char *crt_lin)
{	
	char	buffer[2];

	while (read(map.file, buffer, 1) > 0)
	{
		if (!('0' <= buffer[0] && buffer[0] <= '9'))
		{
			map.empty = buffer[0];
			break ;
		}
		else
			crt_lin = ft_strncat(crt_lin, buffer, 1);
	}
	map.y = convert_str_int(crt_lin);
	return (map);
}

t_map_var	get_char(t_map_var map, int cnt_char)
{	
	char	buffer[2];

	while (read(map.file, buffer, 1) > 0)
	{
		if (buffer[0] == '\n')
			break ;
		else if (cnt_char == 0)
			map.obstacle = buffer[0];
		else if (cnt_char == 1)
			map.full = buffer[0];
		cnt_char++;
		if (cnt_char > 2)
		{	
			map.error = 1;
			return (map);
		}	
	}
	map = check_map_args(map);
	return (map);
}

int	check_char(char *new_line, t_map_var map)
{	
	int	i;

	i = 0;
	while (new_line[i] != '\n' && new_line[i] != EOF)
	{
		if (new_line[i] == EOF)
			return (map.error);
		if (!(new_line[i] == map.empty || new_line[i] == map.obstacle))
			return (1);
		i++;
	}
	return (map.error);
}

t_map_var	loop_char(t_map_var map, int cnt_char, char *new_line)
{	
	char	buffer[2];

	while (read(map.file, buffer, 1) > 0 && map.error == 0)
	{	
		new_line = ft_strncat(new_line, buffer, 1);
		cnt_char++;
		if (cnt_char > map.x && map.crt_lin == 0)
			map.x = cnt_char;
		if (map.x > map.malloc_len && map.crt_lin == 0)
		{
			map.malloc_len += 100;
			new_line = remaloc(map, cnt_char, new_line);
		}
		if (buffer[0] == '\n')
		{	
			map = save_line(map, cnt_char, new_line);
			new_line = create_line(&map);
			cnt_char = 0;
		}
	}
	if (new_line[0] != '\0')
		map.error = 1;
	free(new_line);
	map = check_error_len_map(map, map.crt_lin);
	return (map);
}

t_map_var	get_line(t_map_var map, int cnt_char)
{	
	char	*new_line;

	free(map.map);
	map.map = malloc(sizeof(char *) * map.y);
	if (map.map == 0)
		map.error = 1;
	else
	{
		new_line = create_line(&map);
		cnt_char = 0;
		map.crt_lin = 0;
		map = loop_char(map, cnt_char, new_line);
	}
	return (map);
}
