/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_scale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:38:31 by tquere            #+#    #+#             */
/*   Updated: 2023/01/13 18:56:15 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale(t_fdf *fdf, int x, int y)
{
	t_point_3d	*point_3d_proj;

	point_3d_proj = fdf->mat_3d_proj->array[y * fdf->mat_3d_proj->size_x + x];
	if (point_3d_proj != NULL)
	{
		point_3d_proj->x = (((point_3d_proj->x /
						point_3d_proj->w) + 1) * 0.5) * fdf->res_x;
		point_3d_proj->y = (((point_3d_proj->y /
						point_3d_proj->w) + 1) * 0.5) * fdf->res_y;
		point_3d_proj->z = point_3d_proj->z / point_3d_proj->w;
	}
}
