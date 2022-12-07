/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_point_3d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:22:22 by tquere            #+#    #+#             */
/*   Updated: 2022/12/07 12:24:19 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point_3d	*new_point_3d(t_fdf *fdf, double x, double y, double z)
{
	t_point_3d	*point_3d;

	point_3d = malloc(sizeof(t_point_3d));
	if (point_3d == NULL)
	{
		ft_printf(2, "Error: malloc point_3d\n");
		free_exit(fdf, 1);
	}
	point_3d->x = x;
	point_3d->y = y;
	point_3d->z = z;
	point_3d->w = 0;
	return (point_3d);
}

void	get_mat_3D(t_fdf *fdf)
{
	t_point_3d	*point_3d;
	int			x;
	int			y;
	int			z;

	y = 0;
	while (y < fdf->mat_3d->size_y)
	{
		x = 0;
		while (x < fdf->mat_3d->size_x)
		{	
			z = fdf->map->values[y * fdf->mat_3d->size_x + x];
			point_3d = new_point_3d(fdf, x, y, z);
			point_3d->w = 1;
			fdf->mat_3d->array[y * fdf->mat_3d->size_x + x] = point_3d;
			x++;
		}
		y++;
	}
	free(fdf->map->values);
	fdf->map->values = NULL;
}
