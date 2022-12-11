/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_rotation_prod.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:06:11 by tquere            #+#    #+#             */
/*   Updated: 2022/12/11 12:33:05 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point_3d	*rot_pro_x(t_point_3d *pt, t_matrice *rot)
{	
	t_point_3d	tmp_point;

	tmp_point.x = rot->array[0]->x * pt->x + rot->array[1]->x
		* pt->y + rot->array[2]->x * pt->z;
	tmp_point.y = rot->array[3]->x * pt->x + rot->array[4]->x
		* pt->y + rot->array[5]->x * pt->z;
	tmp_point.z = rot->array[6]->x * pt->x + rot->array[7]->x
		* pt->y + rot->array[8]->x * pt->z;
	pt->x = tmp_point.x;
	pt->y = tmp_point.y;
	pt->z = tmp_point.z;
	return (pt);
}

static t_point_3d	*rot_pro_y(t_point_3d *pt, t_matrice *rot)
{	
	t_point_3d	tmp_point;

	tmp_point.x = rot->array[0]->y * pt->x + rot->array[1]->y
		* pt->y + rot->array[2]->y * pt->z;
	tmp_point.y = rot->array[3]->y * pt->x + rot->array[4]->y
		* pt->y + rot->array[5]->y * pt->z;
	tmp_point.z = rot->array[6]->y * pt->x + rot->array[7]->y
		* pt->y + rot->array[8]->y * pt->z;
	pt->x = tmp_point.x;
	pt->y = tmp_point.y;
	pt->z = tmp_point.z;
	return (pt);
}

static t_point_3d	*rot_pro_z(t_point_3d *pt, t_matrice *rot)
{	
	t_point_3d	tmp_point;

	tmp_point.x = rot->array[0]->z * pt->x + rot->array[1]->z
		* pt->y + rot->array[2]->z * pt->z;
	tmp_point.y = rot->array[3]->z * pt->x + rot->array[4]->z
		* pt->y + rot->array[5]->z * pt->z;
	tmp_point.z = rot->array[6]->z * pt->x + rot->array[7]->z
		* pt->y + rot->array[8]->z * pt->z;
	pt->x = tmp_point.x;
	pt->y = tmp_point.y;
	pt->z = tmp_point.z;
	return (pt);
}

t_point_3d	*rot_point(t_fdf *fdf, t_point_3d *point_3d, t_matrice *matrice_rot)
{	
	if (fdf->r_x != 0)
		point_3d = rot_pro_x(point_3d, matrice_rot);
	if (fdf->r_y != 0)
		point_3d = rot_pro_y(point_3d, matrice_rot);
	if (fdf->r_z != 0)
		point_3d = rot_pro_z(point_3d, matrice_rot);
	return (point_3d);
}
