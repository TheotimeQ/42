/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:00:55 by tquere            #+#    #+#             */
/*   Updated: 2022/12/09 09:17:42 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	stock_line(t_fdf *fdf, char *line, int y)
{
	int		x;
	int		len_line;
	char	**line_values;
	int		nb_values;

	x = 0;
	len_line = ft_strlen(line);
	if (line[len_line - 1] == '\n')
		line[len_line - 1] = '\0';
	line_values = ft_split(line, ' ');
	nb_values = count_split(line_values);
	while (x < nb_values)
	{
		(fdf->map->values)[y * fdf->map->max_x + x] = atoi(line_values[x]);
		x++;
	}

	//Probleme si value louche
	while (x < fdf->map->max_x)
	{
		(fdf->map->values)[y * fdf->map->max_x + x] = 0;
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

static void	malloc_map_value(t_fdf *fdf)
{
	fdf->map->values = malloc(sizeof(int) * fdf->map->max_y * fdf->map->max_x);
	if (fdf == NULL)
	{
		ft_printf(2, "Error: malloc map values\n");
		free_exit(fdf, 1);
	}
}

void	parse_map(t_fdf *fdf)
{
	int	fd;

	malloc_map_value(fdf);
	fd = open(fdf->map->map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf(2, "Error: %s \n", strerror(errno));
		free_exit(fdf, 1);
	}
	get_value_in_map(fdf, fd);
	close(fd);
}
