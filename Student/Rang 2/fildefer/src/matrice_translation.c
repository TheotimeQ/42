/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_translation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:30:53 by tquere            #+#    #+#             */
/*   Updated: 2022/12/06 17:12:45 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate(t_fdf *fdf)
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
				point_3d->x += fdf->cam->t_x;
				point_3d->y += fdf->cam->t_y;
				point_3d->z += fdf->cam->t_z;
			}
			x++;
		}
		y++;
	}
	fdf->cam->t_x = 0;
	fdf->cam->t_y = 0;
	fdf->cam->t_z = 0;
}
