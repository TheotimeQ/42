/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_scale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:38:31 by tquere            #+#    #+#             */
/*   Updated: 2022/12/06 20:29:42 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale_to_res(t_fdf *fdf)
{
	int			x;
	int			y;
	t_point_3d	*point;

	y = 0;
	while (y < fdf->map->max_y)
	{
		x = 0;
		while (x < fdf->map->max_x)
		{	
			point = fdf->mat_3d_proj[y * fdf->map->max_x + x];
			point->x = (((point->x / point->w) + 1) / 2 ) * fdf->res_x;
			point->y = (((point->y / point->w) + 1) / 2 ) * fdf->res_y;
			point->z = point->z / point->w;
			x++;
		}
		y++;
	}
}

