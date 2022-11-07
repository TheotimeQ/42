/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcts_struct_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:43:55 by tquere            #+#    #+#             */
/*   Updated: 2022/10/28 11:42:22 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <unistd.h>

void			init_str(char *str, int size);
t_map_var		get_number(t_map_var map, char *crt_lin);
t_map_var		get_char(t_map_var map, int cnt_char);
t_map_var		get_line(t_map_var map, int cnt_char);
char			*create_line(t_map_var *map);

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

t_map_var	init_map(void)
{
	t_map_var	map;

	map.x = 0;
	map.y = 0;
	map.empty = '\0';
	map.obstacle = '\0';
	map.full = '\0';
	map.map = malloc(1);
	map.sol_x = 0;
	map.sol_y = 0;
	map.sol_side_len = 0;
	map.error = 0;
	map.file = 0;
	map.visual = 0;
	map.last_count_size = 1;
	map.malloc_len = 100;
	return (map);
}

t_map_var	get_map_in_file(t_map_var map)
{
	long int		cnt_char;
	char			*crt_lin;

	cnt_char = 0;
	crt_lin = malloc(20);
	if (crt_lin != 0)
	{
		init_str(crt_lin, 12);
		map = get_number(map, crt_lin);
		map = get_char(map, cnt_char);
		free(crt_lin);
		map = get_line(map, cnt_char);
	}
	else
		map.error = 1;
	return (map);
}

char	*remaloc(t_map_var map, int cnt_char, char *new_line)
{	
	char	*temp_line;

	temp_line = ft_strncpy(create_line(&map), new_line, cnt_char);
	free(new_line);
	return (temp_line);
}
