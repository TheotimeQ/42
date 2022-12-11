/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_translation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:30:53 by tquere            #+#    #+#             */
/*   Updated: 2022/12/11 12:33:06 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	center_map(t_fdf *fdf, int x, int y)
{
	t_point_3d		*point;
	int				size_x;
	double			max_x;
	double			max_y;

	size_x = fdf->mat_3d_proj->size_x;
	point = fdf->mat_3d_proj->array[y * size_x + x];
	if (point == NULL)
		return ;
	max_x = fdf->map->max_x;
	max_y = fdf->map->max_y;
	point->x += -max_x / 2.0 + 0.5;
	point->y += -max_y / 2.0 + 0.5;
	point->z += -fdf->map->max_z / 2.0 - 0.5;
	fdf->mat_3d_proj->array[y * size_x + x] = point;
}

void	translate(t_fdf *fdf, int x, int y)
{
	t_point_3d	*point;
	int			size_x;

	size_x = fdf->mat_3d_proj->size_x;
	point = fdf->mat_3d_proj->array[y * size_x + x];
	if (point == NULL)
		return ;
	point->x += fdf->t_x;
	point->y += fdf->t_y;
	point->z += fdf->t_z;
	fdf->mat_3d_proj->array[y * size_x + x] = point;
}
