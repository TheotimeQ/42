/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:39:41 by tquere            #+#    #+#             */
/*   Updated: 2022/12/07 17:20:14 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double get_rot_value(t_fdf *fdf, int x, int y, t_point_3d *vector)
{   
    double value;
    
    value = 0;
    if (y == 0 && x == 0)
        value = vector->x * vector->x + (1 - vector->x * vector->x) * cos(vector->w);
    else if (y == 0 && x == 1)
        value = vector->x * vector->y * (1 - cos(vector->w)) - vector->z * sin(vector->w);
    else if (y == 0 && x == 2)
        value = vector->x * vector->z * (1 - cos(vector->w)) + vector->y * sin(vector->w);
    else if (y == 1 && x == 0)
        value = vector->x * vector->y * (1 - cos(vector->w)) + vector->z * sin(vector->w);
    else if (y == 1 && x == 1)
        value = vector->y * vector->y + (1 - vector->y * vector->y) * cos(vector->w);
    else if (y == 1 && x == 2)
        value = vector->y * vector->z * (1 - cos(vector->w)) - vector->x * sin(vector->w);
    else if (y == 2 && x == 0)
        value = vector->x * vector->z * (1 - cos(vector->w)) - vector->y * sin(vector->w);
    else if (y == 2 && x == 1)
        value = vector->y * vector->z * (1 - cos(vector->w)) + vector->x * sin(vector->w);
    else if (y == 2 && x == 2)
        value = vector->z * vector->z + (1 - vector->z * vector->z) * cos(vector->w);
    return (value);
}

void	get_mat_rot(t_fdf *fdf)
{
	int	        x;
	int	        y;
    int         sz_x;

    sz_x = fdf->mat_rot->size_x;
	y = 0;
	while (y < fdf->mat_rot->size_y)
	{
		x = 0;
		while (x < sz_x)
		{   
            if (fdf->mat_rot->array[y * sz_x + x] == NULL)
                fdf->mat_rot->array[y * sz_x + x] = new_point_3d(fdf, 0, 0, 0);
            fdf->mat_rot->array[y * sz_x + x]->x = get_rot_value(fdf, x, y, fdf->u_x);
            fdf->mat_rot->array[y * sz_x + x]->y = get_rot_value(fdf, x, y, fdf->u_y);
            fdf->mat_rot->array[y * sz_x + x]->z = get_rot_value(fdf, x, y, fdf->u_z);
            x++;
		}
		y++;
	}
}

void	rotate(t_fdf *fdf, int x, int y)
{
	t_point_3d	*point_3d;
    int         size_x;

    size_x = fdf->mat_3d->size_x;
	point_3d = fdf->mat_3d->array[y * size_x + x];
    if (point_3d == NULL)
        return ;
    if (point_3d == NULL)
        point_3d = new_point_3d(fdf, 0, 0, 0);
    point_3d = rot_point(fdf, point_3d, fdf->mat_rot);
    fdf->mat_3d->array[y * size_x + x] = point_3d;
}
