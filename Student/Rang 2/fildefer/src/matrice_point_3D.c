/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_point_3D.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:22:22 by tquere            #+#    #+#             */
/*   Updated: 2022/12/06 15:53:47 by tquere           ###   ########.fr       */
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

void	init_mat_3d(t_fdf *fdf, t_point_3d	**mat)
{
	int		x;
	int		y;

	y = 0;
	while (y < fdf->map->max_y)
	{
		x = 0;
		while (x < fdf->map->max_x)
		{
			mat[y * fdf->map->max_x + x] = NULL;
			x++;
		}
		y++;
	}
}

void	get_value_mat_3d(t_fdf *fdf)
{
	t_point_3d	*point_3d;
	int			x;
	int			y;
	int			z;

	y = 0;
	while (y < fdf->map->max_y)
	{
		x = 0;
		while (x < fdf->map->max_x)
		{	
			z = fdf->map->values[y * fdf->map->max_x + x];
			point_3d = new_point_3d(fdf, x, y, z);
			point_3d->w = 1;
			fdf->mat_3d[y * fdf->map->max_x + x] = point_3d;
			x++;
		}
		y++;
	}
}

			// else
			// {
			// 	fdf->mat_3d[y * fdf->map->max_x + x]->x = x;
			// 	fdf->mat_3d[y * fdf->map->max_x + x]->y = y;
			// 	fdf->mat_3d[y * fdf->map->max_x + x]->z = z;
			// 	fdf->mat_3d[y * fdf->map->max_x + x]->w = 1;
			// }
