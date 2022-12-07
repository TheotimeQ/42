/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:29:53 by tquere            #+#    #+#             */
/*   Updated: 2022/12/07 23:23:36 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_img(t_fdf *fdf)
{
	int			x;
	int			y;
	double		x_point;
	double		y_point;
	int			color;
	t_point_3d *point;


	color = 0xFFFFFF;

	y = 0;
	while (y < fdf->map->max_y)
	{
		x = 0;
		while (x < fdf->map->max_x)
		{	
			point = fdf->mat_3d_proj->array[y * fdf->map->max_x + x];
			if (point)
			{
				x_point = point->x;
				y_point = point->y;
				draw_point(fdf, x_point, y_point, color);
			}
			x++;
		}
		y++;
	}

	t_point_3d	*point_1;
	t_point_3d	*point_2;

	y = 0;
	color = 0x909090;
	while (y < fdf->map->max_y)
	{
		x = 0;
		while (x < fdf->map->max_x - 1)
		{
			point_1 = fdf->mat_3d_proj->array[y * fdf->map->max_x + x];
			point_2 = fdf->mat_3d_proj->array[y * fdf->map->max_x + x + 1];
			draw_ligne(fdf, point_1, point_2, color);
			x++;
		}
		y++;
	}

	y = 0;
	while (y < fdf->map->max_y - 1)
	{
		x = 0;
		while (x < fdf->map->max_x)
		{
			point_1 = fdf->mat_3d_proj->array[y * fdf->map->max_x + x];
			point_2 = fdf->mat_3d_proj->array[(y + 1) * fdf->map->max_x + x];
			draw_ligne(fdf, point_1, point_2, color);
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
	fill_img(fdf);
	// mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
