/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:52:47 by tquere            #+#    #+#             */
/*   Updated: 2022/12/11 12:32:58 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_value_error(t_fdf *fdf, char **values)
{
	int				index;
	long int		value;

	index = 0;
	while (values[index])
	{
		if (ft_isnum(values[index]) == 0)
			return (1);
		value = ft_atoi(values[index]);
		if (value < INT_MIN || INT_MAX < value)
			return (1);
		if (value < fdf->map->min_z)
			fdf->map->min_z = value;
		if (fdf->map->max_z < value)
			fdf->map->max_z = value;
		index++;
	}
	return (0);
}

static void	first_line(t_fdf *fdf, char *line)
{
	int		len_line;
	char	**line_values;

	len_line = ft_strlen(line);
	if (line[len_line - 1] == '\n')
		line[len_line - 1] = '\0';
	line_values = ft_split(line, ' ');
	if (is_value_error(fdf, line_values))
	{
		ft_printf(2, "Error : wrong value in map\n");
		free_split(line_values);
		free(line);
		free_exit(fdf, 1);
	}
	fdf->map->max_x = count_split(line_values);
	fdf->map->max_y++;
	free_split(line_values);
}

static void	other_line(t_fdf *fdf, char *line)
{
	int		len_line;
	char	**line_values;

	len_line = ft_strlen(line);
	if (line[len_line - 1] == '\n')
		line[len_line - 1] = '\0';
	line_values = ft_split(line, ' ');
	if (is_value_error(fdf, line_values))
	{
		ft_printf(2, "Error : wrong value in map\n");
		free_split(line_values);
		free(line);
		free_exit(fdf, 1);
	}
	if (count_split(line_values) > fdf->map->max_x)
		fdf->map->max_x = count_split(line_values);
	fdf->map->max_y++;
	free_split(line_values);
}

void	get_map_size(t_fdf *fdf, int fd)
{
	char		*line;

	line = get_next_line(fd);
	if (line == NULL)
		return ;
	first_line(fdf, line);
	while (line != NULL)
	{	
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		other_line(fdf, line);
	}
	free(line);
}
