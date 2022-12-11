/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:29:53 by tquere            #+#    #+#             */
/*   Updated: 2022/12/11 12:33:07 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_vert(t_fdf *fdf)
{
	int			x;
	int			y;
	t_point_3d	*point_1;
	t_point_3d	*point_2;

	y = 0;
	while (y < fdf->map->max_y)
	{
		x = 0;
		while (x < fdf->map->max_x - 1)
		{
			point_1 = fdf->mat_3d_proj->array[y * fdf->map->max_x + x];
			point_2 = fdf->mat_3d_proj->array[y * fdf->map->max_x + x + 1];
			draw_ligne(fdf, point_1, point_2);
			x++;
		}
		y++;
	}
}

static void	draw_hori(t_fdf *fdf)
{
	int			x;
	int			y;
	t_point_3d	*point_1;
	t_point_3d	*point_2;

	y = 0;
	while (y < fdf->map->max_y - 1)
	{
		x = 0;
		while (x < fdf->map->max_x)
		{
			point_1 = fdf->mat_3d_proj->array[y * fdf->map->max_x + x];
			point_2 = fdf->mat_3d_proj->array[(y + 1) * fdf->map->max_x + x];
			draw_ligne(fdf, point_1, point_2);
			x++;
		}
		y++;
	}
}

void	update_img(t_fdf *fdf)
{	
	if (fdf->img != NULL)
		mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_clear_window(fdf->mlx, fdf->win);
	fdf->img = mlx_new_image(fdf->mlx, fdf->res_x, fdf->res_y);
	draw_vert(fdf);
	draw_hori(fdf);
}
