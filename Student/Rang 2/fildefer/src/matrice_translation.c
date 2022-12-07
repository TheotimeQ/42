/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_translation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:30:53 by tquere            #+#    #+#             */
/*   Updated: 2022/12/07 18:22:16 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate(t_fdf *fdf, int x, int y)
{
	t_point_3d	*point_3d;
    int         size_x;

    size_x = fdf->mat_3d->size_x;
	point_3d = fdf->mat_3d->array[y * size_x + x];
    if (point_3d == NULL)
        return ;
    point_3d->x += fdf->cam->t_x;
    point_3d->y += fdf->cam->t_y;
    point_3d->z += fdf->cam->t_z;
    fdf->mat_3d->array[y * size_x + x] = point_3d;
}
