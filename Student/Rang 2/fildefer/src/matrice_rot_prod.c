/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_rot_prod.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:06:11 by tquere            #+#    #+#             */
/*   Updated: 2022/12/06 18:06:58 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	rot_pro_x(t_fdf *fdf, t_point_3d *point_3d, double *mat_rot)
{	
	double		x;

	x = mat_rot[0] * point_3d->x;
	x += mat_rot[1] * point_3d->y;
	x += mat_rot[2] * point_3d->z;
	return (x);
}

static double	rot_pro_y(t_fdf *fdf, t_point_3d *point_3d, double *mat_rot)
{	
	double		y;

	y = mat_rot[3] * point_3d->x;
	y += mat_rot[4] * point_3d->y;
	y += mat_rot[5] * point_3d->z;
	return (y);
}

static double	rot_pro_z(t_fdf *fdf, t_point_3d *point_3d, double *mat_rot)
{	
	double		z;

	z = mat_rot[6] * point_3d->x;
	z += mat_rot[7] * point_3d->y;
	z += mat_rot[8] * point_3d->z;
	return (z);
}

t_point_3d	*rot_point(t_fdf *fdf, t_point_3d *point_3d, double *mat_rot)
{
	point_3d->x = rot_pro_x(fdf, point_3d, mat_rot);
	point_3d->y = rot_pro_y(fdf, point_3d, mat_rot);
	point_3d->z = rot_pro_z(fdf, point_3d, mat_rot);
	return (point_3d);
}
