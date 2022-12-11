/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:00:55 by tquere            #+#    #+#             */
/*   Updated: 2022/12/11 12:33:03 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	stock_line(t_fdf *fdf, char *line, int y)
{
	int			x;
	int			len_line;
	char		**line_values;
	int			nb_values;
	t_point_3d	*point_3d;

	x = 0;
	len_line = ft_strlen(line);
	if (line[len_line - 1] == '\n')
		line[len_line - 1] = '\0';
	line_values = ft_split(line, ' ');
	nb_values = count_split(line_values);
	while (x < nb_values)
	{	
		point_3d = new_point_3d(fdf, x, y, atoi(line_values[x]));
		point_3d->w = 1;
		fdf->mat_3d->array[y * fdf->map->max_x + x] = point_3d;
		x++;
	}
	while (x < fdf->map->max_x)
	{
		fdf->mat_3d->array[y * fdf->map->max_x + x] = NULL;
		x++;
	}
	free_split(line_values);
}

static void	get_value_in_map(t_fdf *fdf, int fd)
{
	char	*line;
	int		y;

	y = 0;
	line = get_next_line(fd);
	if (line == NULL)
		return ;
	stock_line(fdf, line, y);
	y++;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		stock_line(fdf, line, y);
		y++;
	}
	free(line);
}

void	parse_map(t_fdf *fdf)
{
	int	fd;

	fd = open(fdf->map->map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf(2, "Error: %s \n", strerror(errno));
		free_exit(fdf, 1);
	}
	get_value_in_map(fdf, fd);
	close(fd);
}
