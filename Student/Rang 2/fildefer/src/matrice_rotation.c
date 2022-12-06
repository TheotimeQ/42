/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:39:41 by tquere            #+#    #+#             */
/*   Updated: 2022/12/06 17:12:20 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point_3d	*rotate_x(t_fdf *fdf, t_point_3d *point_3d)
{

	return (point_3d);
}

static t_point_3d	*rotate_y(t_fdf *fdf, t_point_3d *point_3d)
{

	return (point_3d);
}

static t_point_3d	*rotate_z(t_fdf *fdf, t_point_3d *point_3d)
{

	return (point_3d);
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
				point_3d = rotate_x(fdf, point_3d);
				point_3d = rotate_y(fdf, point_3d);
				point_3d = rotate_z(fdf, point_3d);
			}
			x++;
		}
		y++;
	}
	fdf->cam->r_x = 0;
	fdf->cam->r_y = 0;
	fdf->cam->r_z = 0;
}
