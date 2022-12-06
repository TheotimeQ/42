/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:39:41 by tquere            #+#    #+#             */
/*   Updated: 2022/12/06 18:12:43 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mat_rot(t_fdf *fdf, double *mat_rot)
{
	int	x;
	int	y;

	y = 0;
	while (y < 3)
	{
		x = 0;
		while (x < 3)
		{
			mat_rot[y * 3 + x] = 0;
			x++;
		}
		y++;
	}
}

void	get_mat_rot_x(t_fdf *fdf)
{
	fdf->mat_rot_x[0 * 3 + 0] = 1;
	fdf->mat_rot_x[1 * 3 + 1] = cos(fdf->cam->r_x);
	fdf->mat_rot_x[1 * 3 + 2] = -sin(fdf->cam->r_x);
	fdf->mat_rot_x[2 * 3 + 1] = sin(fdf->cam->r_x);
	fdf->mat_rot_x[2 * 3 + 2] = cos(fdf->cam->r_x);
}

void	get_mat_rot_y(t_fdf *fdf)
{
	fdf->mat_rot_y[0 * 3 + 0] = cos(fdf->cam->r_y);
	fdf->mat_rot_y[0 * 3 + 2] = sin(fdf->cam->r_y);
	fdf->mat_rot_y[1 * 3 + 1] = 1;
	fdf->mat_rot_y[2 * 3 + 0] = -sin(fdf->cam->r_y);
	fdf->mat_rot_y[2 * 3 + 2] = cos(fdf->cam->r_y);
}

void	get_mat_rot_z(t_fdf *fdf)
{
	fdf->mat_rot_z[0 * 3 + 0] = cos(fdf->cam->r_z);
	fdf->mat_rot_z[0 * 3 + 1] = -sin(fdf->cam->r_z);
	fdf->mat_rot_z[1 * 3 + 0] = sin(fdf->cam->r_z);
	fdf->mat_rot_z[1 * 3 + 1] = cos(fdf->cam->r_z);
	fdf->mat_rot_z[2 * 3 + 2] = 1;
}

void	rotate(t_fdf *fdf)
{
	int			x;
	int			y;
	t_point_3d	*point_3d;

	y = 0;
	while (y < fdf->map->max_y)
	{
		x = 0;
		while (x < fdf->map->max_x)
		{	
			point_3d = fdf->mat_3d[y * fdf->map->max_x + x];
			if (point_3d)
			{	
				point_3d = rot_point(fdf, point_3d, fdf->mat_rot_x);
				point_3d = rot_point(fdf, point_3d, fdf->mat_rot_y);
				point_3d = rot_point(fdf, point_3d, fdf->mat_rot_z);
				fdf->mat_3d[y * fdf->map->max_x + x] = point_3d;
			}
			x++;
		}
		y++;
	}
	fdf->cam->r_x = 0;
	fdf->cam->r_y = 0;
	fdf->cam->r_z = 0;
}
