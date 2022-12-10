/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:29:53 by tquere            #+#    #+#             */
/*   Updated: 2022/12/09 12:11:27 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		get_color(t_fdf *fdf, t_point_3d *point, int x, int y)
{
	int			color;
	int 		alt;

	alt = fdf->mat_3d->array[y * fdf->map->max_x + x]->z;
	color = fdf->min_color + (fdf->max_color - fdf->min_color) * alt / fdf->map->max_z;
	point->w = color;
}

static void	draw_on_img(t_fdf *fdf)
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
			get_color(fdf, point_1, x, y);
			get_color(fdf, point_2, x, y);
			draw_ligne(fdf, point_1, point_2);
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
	draw_on_img(fdf);
	// mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
