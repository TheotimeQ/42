/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:33:14 by tquere            #+#    #+#             */
/*   Updated: 2022/12/06 15:38:19 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mat_proj(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			fdf->mat_proj[y * 4 + x] = 0;
			x++;
		}
		y++;
	}
}

void	get_mat_proj(t_fdf *fdf)
{
	fdf->mat_proj[0 * 4 + 0] = fdf->ratio * 1 / tan(fdf->cam->fov / 2);
	fdf->mat_proj[1 * 4 + 1] = 1 / tan(fdf->cam->fov / 2);
	fdf->mat_proj[2 * 4 + 2] = fdf->cam->z_max
		/ (fdf->cam->z_max - fdf->cam->z_min);
	fdf->mat_proj[2 * 4 + 3] = (-fdf->cam->z_max * fdf->cam->z_min)
		/ (fdf->cam->z_max - fdf->cam->z_min);
	fdf->mat_proj[3 * 4 + 2] = 1;
}

void	apply_proj(t_fdf *fdf)
{
	int			x;
	int			y;
	t_point_3d	*point_3d;
	t_point_3d	*point_3d_proj;

	y = 0;
	while (y < fdf->map->max_y)
	{
		x = 0;
		while (x < fdf->map->max_x)
		{	
			point_3d = fdf->mat_3d[y * fdf->map->max_x + x];
			if (point_3d)
			{	
				point_3d_proj = fdf->mat_3d_proj[y * fdf->map->max_x + x];
				if (!point_3d_proj)
					point_3d_proj = new_point_3d(fdf, 0, 0, 0);
				point_3d_proj->x = proj_product_x(fdf, point_3d);
				point_3d_proj->y = proj_product_y(fdf, point_3d);
				point_3d_proj->z = proj_product_z(fdf, point_3d);
				point_3d_proj->w = proj_product_w(fdf, point_3d);
				fdf->mat_3d_proj[y * fdf->map->max_x + x] = point_3d_proj;
			}
			x++;
		}
		y++;
	}
}
