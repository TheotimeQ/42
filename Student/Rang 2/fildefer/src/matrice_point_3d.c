/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_point_3d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:22:22 by tquere            #+#    #+#             */
/*   Updated: 2022/12/11 12:33:04 by tquere           ###   ########.fr       */
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
