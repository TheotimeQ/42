/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcts_resolve_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:16:42 by tquere            #+#    #+#             */
/*   Updated: 2022/07/27 13:59:24 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>

void	ft_putstr(char *str, int output, int visual);

void	print_map(t_map_var map)
{
	int	idx_y;

	idx_y = 0;
	if (map.visual == 1)
		write(1, " ", 1);
	while (idx_y < map.y)
	{
		ft_putstr(map.map[idx_y], 1, map.visual);
		idx_y++;
	}
}

t_map_var	check_column(t_map_var map, int x, int y, int count_size)
{	
	int		idx_x;
	int		idx_y;

	idx_x = x + count_size;
	idx_y = y ;
	while (idx_y - y <= count_size && map.stop == 0)
	{	
		if (idx_y >= map.y || idx_x > map.x)
			map.stop = 1;
		else if (map.map[idx_y][idx_x] == map.obstacle
			|| map.map[idx_y][idx_x] == '\n')
			map.stop = 1;
		else
			idx_y++;
	}
	if (idx_y > map.y || idx_x > map.x)
	{
		map.stop = 1;
	}
	return (map);
}

t_map_var	check_line(t_map_var map, int x, int y, int count_size)
{
	int		idx_x;
	int		idx_y;

	idx_x = x ;
	idx_y = y + count_size ;
	while (idx_x - x < count_size && map.stop == 0)
	{	
		if (idx_y >= map.y || idx_x > map.x)
			map.stop = 1;
		else if (map.map[idx_y][idx_x] == map.obstacle
			|| map.map[idx_y][idx_x] == '\n')
			map.stop = 1;
		else
			idx_x++;
	}
	if (idx_y > map.y || idx_x > map.x)
	{
		map.stop = 1;
	}
	return (map);
}

t_map_var	check_logic(t_map_var map, int x, int y, int count_size)
{
	map = check_column(map, x, y, count_size);
	map = check_line(map, x, y, count_size);
	return (map);
}

t_map_var	check_error_len_map(t_map_var map, int crt_lin)
{	
	if (map.y != crt_lin || map.error == 1 || map.y == 0 || map.x == 0)
	{	
		if (crt_lin < map.y)
			map.y = crt_lin;
		map.error = 1;
	}
	return (map);
}
