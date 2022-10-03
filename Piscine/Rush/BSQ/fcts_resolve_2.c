/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcts_resolve_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:38:34 by tquere            #+#    #+#             */
/*   Updated: 2022/07/27 16:05:42 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

t_map_var		check_logic(t_map_var map, int x, int y, int count_size);
void			init_str(char *str, int size);
int				check_char(char *new_line, t_map_var map);

t_map_var	save_line(t_map_var map, int cnt_char, char *new_line)
{	
	map.error = check_char(new_line, map);
	if (cnt_char != map.x || new_line[0] == '\n')
		map.error = 1;
	if (cnt_char > 1)
	{	
		if (map.crt_lin < map.y)
		{
			map.map[map.crt_lin] = new_line;
		}
		map.crt_lin++;
	}
	return (map);
}

void	free_map(t_map_var map)
{	
	int	idx_y;

	idx_y = 0;
	while (idx_y < map.y)
	{	
		free(map.map[idx_y]);
		idx_y++;
	}
	free(map.map);
	return ;
}

t_map_var	check_square(t_map_var map, int x, int y)
{
	int		count_size;

	count_size = map.last_count_size;
	map.stop = 0;
	while (map.stop == 0)
	{	
		map = check_logic(map, x, y, count_size);
		count_size++;
	}
	map.last_count_size = count_size - 2;
	if (map.sol_side_len < count_size - 1)
	{	
		map.sol_side_len = count_size - 1;
		map.sol_x = x;
		map.sol_y = y;
	}
	return (map);
}

t_map_var	resolve_map(t_map_var map)
{
	int	idx_x;
	int	idx_y;

	map.sol_x = 0;
	map.sol_y = 0;
	idx_x = map.sol_x;
	idx_y = map.sol_y;
	map.sol_side_len = 0;
	while (idx_y < map.y - map.sol_side_len)
	{	
		idx_x = 0;
		while (idx_x < map.x - map.sol_side_len - 1)
		{	
			if (map.map[idx_y][idx_x] != map.obstacle)
				map = check_square(map, idx_x, idx_y);
			idx_x++;
		}
		idx_y++;
	}
	return (map);
}

char	*create_line(t_map_var *map)
{	
	char	*new_line;

	new_line = malloc(sizeof(char) * (map->malloc_len + 1));
	if (new_line == 0)
		map->error = 1;
	init_str(new_line, map->malloc_len);
	return (new_line);
}
