/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:33:14 by tquere            #+#    #+#             */
/*   Updated: 2022/12/11 12:33:04 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point_3d	*point_proj(t_fdf *fdf, double pt_x, t_point_3d *point)
{
	if (point == NULL)
		point = new_point_3d(fdf, pt_x, 0, 0);
	point->x = pt_x;
	return (point);
}

static t_point_3d	*get_proj_value(t_fdf *fdf, int x, int y, t_point_3d *point)
{
	if (y == 0 && x == 0)
		return (point_proj(fdf, fdf->ratio * 1
				/ tan(fdf->cam->fov / 2), point));
	else if (y == 1 && x == 1)
		return (point_proj(fdf, 1 / tan(fdf->cam->fov / 2), point));
	else if (y == 2 && x == 2)
		return (point_proj(fdf, fdf->cam->z_max
				/ (fdf->cam->z_max - fdf->cam->z_min), point));
	else if (y == 2 && x == 3)
		return (point_proj(fdf, (-fdf->cam->z_max * fdf->cam->z_min)
				/ (fdf->cam->z_max - fdf->cam->z_min), point));
	else if (y == 3 && x == 2)
		return (point_proj(fdf, 1, point));
	return (NULL);
}

void	get_mat_proj(t_fdf *fdf)
{
	int			x;
	int			y;
	t_point_3d	*point;

	y = 0;
	while (y < fdf->mat_proj->size_y)
	{
		x = 0;
		while (x < fdf->mat_proj->size_x)
		{
			point = fdf->mat_proj->array[y * fdf->mat_proj->size_x + x];
			point = get_proj_value(fdf, x, y, point);
			fdf->mat_proj->array[y * fdf->mat_proj->size_x + x] = point;
			x++;
		}
		y++;
	}
}

void	cpy_point_3d(t_fdf *fdf, int x, int y)
{
	t_point_3d	*point;
	t_point_3d	*point_proj;
	int			size_x;

	size_x = fdf->mat_3d_proj->size_x;
	point = fdf->mat_3d->array[y * size_x + x];
	point_proj = fdf->mat_3d_proj->array[y * size_x + x];
	if (point_proj != NULL)
		free(point_proj);
	point_proj = new_point_3d(fdf, 0, 0, 0);
	point_proj->x = point->x;
	point_proj->y = point->y;
	point_proj->z = point->z;
	point_proj->w = point->w;
	fdf->mat_3d_proj->array[y * size_x + x] = point_proj;
}

void	project(t_fdf *fdf, int x, int y)
{
	t_point_3d	*point;
	int			size_x;
	t_matrice	*mat_proj;

	mat_proj = fdf->mat_proj;
	size_x = fdf->mat_3d_proj->size_x;
	point = fdf->mat_3d_proj->array[y * size_x + x];
	if (point == NULL)
		return ;
	point->x = mat_proj->array[0]->x * point->x;
	point->y = mat_proj->array[5]->x * point->y;
	point->z = mat_proj->array[10]->x * point->z
		+ mat_proj->array[11]->x * point->z;
	point->w = mat_proj->array[14]->x * point->z;
	fdf->mat_3d_proj->array[y * size_x + x] = point;
}
