/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:06:17 by tquere            #+#    #+#             */
/*   Updated: 2022/11/11 16:10:23 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>

#define VISUAL 0

void			ft_putchar(char c, int output);
void			ft_putstr(char *str, int output, int visual);
void			print_map(t_map_var map);
t_map_var		resolve_map(t_map_var map);
t_map_var		init_map(void);
t_map_var		get_map_in_file(t_map_var map);
void			free_map(t_map_var map);

t_map_var	add_sol(t_map_var map)
{	
	int		idx_x;
	int		idx_y;

	idx_x = map.sol_x;
	idx_y = map.sol_y;
	while (idx_y < map.sol_y + map.sol_side_len)
	{	
		idx_x = map.sol_x;
		while (idx_x < map.sol_x + map.sol_side_len)
		{	
			if (idx_y < map.y && idx_x <= map.x - 1)
				map.map[idx_y][idx_x] = map.full;
			idx_x++;
		}
		idx_y++;
	}
	return (map);
}

void	work_on_map(t_map_var map)
{	
	map = resolve_map(map);
	map = add_sol(map);
	print_map(map);
	free_map(map);
	return ;
}

void	open_map_and_solve(int file)
{	
	t_map_var	map;

	map = init_map();
	if (map.map == 0)
		map.error = 1;
	map.file = file;
	map.visual = VISUAL;
	if (!map.error)
		map = get_map_in_file(map);
	if (!map.error)
		work_on_map(map);
	else
	{
		free_map(map);
		ft_putstr("map error\n", 1, 0);
	}
}

void	loop_on_file(int argc, char **argv)
{
	int			index;
	char		*file_name;
	int			file;

	index = 1;
	while (index < argc)
	{
		file_name = argv[index++];
		file = open(file_name, O_RDWR);
		if (file == -1)
			ft_putstr("map error\n", 1, 0);
		else
		{	
			open_map_and_solve(file);
		}
		if (argc > 2)
			ft_putstr("\n", 1, 0);
		close(file);
	}
}

int	main(int argc, char **argv)
{	
	if (argc == 1)
	{	
		open_map_and_solve(STDIN_FILENO);
		return (0);
	}
	loop_on_file(argc, argv);
	return (0);
}
