/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_product.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:06:11 by tquere            #+#    #+#             */
/*   Updated: 2022/12/06 15:09:55 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	proj_product_x(t_fdf *fdf, t_point_3d *point_3d)
{	
	double		x;

	x = fdf->mat_proj[0] * point_3d->x;
	x += fdf->mat_proj[1] * point_3d->y;
	x += fdf->mat_proj[2] * point_3d->z;
	x += fdf->mat_proj[3] * point_3d->w;
	return (x);
}

double	proj_product_y(t_fdf *fdf, t_point_3d *point_3d)
{	
	double		y;

	y = fdf->mat_proj[4] * point_3d->x;
	y += fdf->mat_proj[5] * point_3d->y;
	y += fdf->mat_proj[6] * point_3d->z;
	y += fdf->mat_proj[7] * point_3d->w;
	return (y);
}

double	proj_product_z(t_fdf *fdf, t_point_3d *point_3d)
{	
	double		z;

	z = fdf->mat_proj[8] * point_3d->x;
	z += fdf->mat_proj[9] * point_3d->y;
	z += fdf->mat_proj[10] * point_3d->z;
	z += fdf->mat_proj[11] * point_3d->w;
	return (z);
}

double	proj_product_w(t_fdf *fdf, t_point_3d *point_3d)
{	
	double		w;

	w = fdf->mat_proj[12] * point_3d->x;
	w += fdf->mat_proj[13] * point_3d->y;
	w += fdf->mat_proj[14] * point_3d->z;
	w += fdf->mat_proj[15] * point_3d->w;
	return (w);
}
