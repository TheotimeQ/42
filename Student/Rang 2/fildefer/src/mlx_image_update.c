/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:29:53 by tquere            #+#    #+#             */
/*   Updated: 2022/12/06 16:47:00 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_img(t_fdf *fdf)
{
	int		x;
	int		y;
	double	x_point;
	double	y_point;

	y = 0;
	while (y < fdf->map->max_y)
	{
		x = 0;
		while (x < fdf->map->max_x)
		{
			x_point = fdf->mat_3d_proj[y * fdf->map->max_x + x]->x;
			y_point = fdf->mat_3d_proj[y * fdf->map->max_x + x]->y;
			draw_point(fdf, x_point, y_point);
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
