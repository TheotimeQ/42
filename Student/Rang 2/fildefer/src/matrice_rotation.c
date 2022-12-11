/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:39:41 by tquere            #+#    #+#             */
/*   Updated: 2022/12/11 12:33:06 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	get_rot_value_x(t_fdf *fdf, int x, int y)
{
	double	value;

	value = 0;
	if (y == 0 && x == 0)
		value = 1;
	else if (y == 1 && x == 1)
		value = cos(fdf->r_x);
	else if (y == 1 && x == 2)
		value = -sin(fdf->r_x);
	else if (y == 2 && x == 1)
		value = sin(fdf->r_x);
	else if (y == 2 && x == 2)
		value = cos(fdf->r_x);
	return (value);
}

static double	get_rot_value_y(t_fdf *fdf, int x, int y)
{
	double	value;

	value = 0;
	if (y == 0 && x == 0)
		value = cos(fdf->r_y);
	else if (y == 0 && x == 2)
		value = sin(fdf->r_y);
	else if (y == 1 && x == 1)
		value = 1;
	else if (y == 2 && x == 0)
		value = -sin(fdf->r_y);
	else if (y == 2 && x == 2)
		value = cos(fdf->r_y);
	return (value);
}

static double	get_rot_value_z(t_fdf *fdf, int x, int y)
{
	double	value;

	value = 0;
	if (y == 0 && x == 0)
		value = cos(fdf->r_z);
	else if (y == 0 && x == 1)
		value = -sin(fdf->r_z);
	else if (y == 1 && x == 0)
		value = sin(fdf->r_z);
	else if (y == 1 && x == 1)
		value = cos(fdf->r_z);
	else if (y == 2 && x == 2)
		value = 1;
	return (value);
}

void	get_mat_rot(t_fdf *fdf)
{
	int		x;
	int		y;
	int		sz_x;

	sz_x = fdf->mat_rot->size_x;
	y = 0;
	while (y < fdf->mat_rot->size_y)
	{
		x = 0;
		while (x < sz_x)
		{
			if (fdf->mat_rot->array[y * sz_x + x] == NULL)
				fdf->mat_rot->array[y * sz_x + x] = new_point_3d(fdf, 0, 0, 0);
			fdf->mat_rot->array[y * sz_x + x]->x = get_rot_value_x(fdf, x, y);
			fdf->mat_rot->array[y * sz_x + x]->y = get_rot_value_y(fdf, x, y);
			fdf->mat_rot->array[y * sz_x + x]->z = get_rot_value_z(fdf, x, y);
			x++;
		}
		y++;
	}
}

void	rotate(t_fdf *fdf, int x, int y)
{
	t_point_3d		*point;
	int				size_x;

	size_x = fdf->mat_3d_proj->size_x;
	point = fdf->mat_3d_proj->array[y * size_x + x];
	if (point == NULL)
		return ;
	point = rot_point(fdf, point, fdf->mat_rot);
	fdf->mat_3d_proj->array[y * size_x + x] = point;
}
