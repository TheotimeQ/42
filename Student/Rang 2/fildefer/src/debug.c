/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:55:55 by tquere            #+#    #+#             */
/*   Updated: 2022/12/06 15:48:23 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map->max_y)
	{
		x = 0;
		while (x < fdf->map->max_x)
		{
			ft_printf(1, "%d ", fdf->map->values[y * fdf->map->max_x + x]);
			x++;
		}
		ft_printf(1, "\n");
		y++;
	}
	ft_printf(1, "\n");
}

void	print_mat_3d(t_fdf *fdf, t_point_3d **mat)
{
	int			x;
	int			y;
	t_point_3d	*point;

	y = 0;
	while (y < fdf->map->max_y)
	{
		x = 0;
		while (x < fdf->map->max_x)
		{
			if (mat[y * fdf->map->max_x + x] != NULL)
			{	
				point = mat[y * fdf->map->max_x + x];
				printf("%.1f %.1f %.1f %.1f | ", point->x, point->y, point->z, point->w);
			}
			else
				printf("NULL | ");
			x++;
		}
		printf("\n");
		y++;
	}
	ft_printf(1, "\n");
}

void	print_mat_proj(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			printf("%.2f | ", fdf->mat_proj[y * 4 + x]);
			x++;
		}
		printf("\n");
		y++;
	}
	ft_printf(1, "\n");
}
