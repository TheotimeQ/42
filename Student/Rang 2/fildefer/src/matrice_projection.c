/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:33:14 by tquere            #+#    #+#             */
/*   Updated: 2022/12/07 18:03:46 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point_3d *point_proj(t_fdf *fdf, double pt_x, t_point_3d *point)
{
    if (point == NULL)
        point = new_point_3d(fdf, pt_x, 0, 0);
    point->x = pt_x;
    return (point);
}

static t_point_3d *get_proj_value(t_fdf *fdf, int x, int y, t_point_3d *point)
{   
    double value;

    if (y == 0 && x == 0)
    {
        value = fdf->ratio * 1 / tan(fdf->cam->fov / 2);
        return (point_proj(fdf, value, point));
    }
    else if (y == 1 && x == 1)
    {
        value = 1 / tan(fdf->cam->fov / 2);
        return (point_proj(fdf, value, point));
    }
    else if (y == 2 && x == 2)
    {
        value = fdf->cam->z_max / (fdf->cam->z_max - fdf->cam->z_min);
        return (point_proj(fdf, value, point));
    }
    else if (y == 2 && x == 3)
    {
        value = (-fdf->cam->z_max * fdf->cam->z_min) / (fdf->cam->z_max - fdf->cam->z_min);
        return (point_proj(fdf, value, point));
    }
    else if (y == 3 && x == 2)
    {
        value = 1;
        return (point_proj(fdf, value, point));
    }
    return (NULL);
}

void	get_mat_proj(t_fdf *fdf)
{
	int	        x;
	int	        y;
    t_point_3d  *point;

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

	// t_point_3d	*point_3d;
    // int         size_x;

    // size_x = fdf->mat_3d->size_x;
	// point_3d = fdf->mat_3d->array[y * size_x + x];
    // if (point_3d == NULL)
    //     return ;
    // if (point_3d == NULL)
    //     point_3d = new_point_3d(fdf, 0, 0, 0);
    // point_3d = rot_point(fdf, point_3d, fdf->mat_rot);
    // fdf->mat_3d->array[y * size_x + x] = point_3d;
    
void	project(t_fdf *fdf, int x, int y)
{
	t_point_3d	*point_3d;
    t_matrice	*mat_proj;
	t_point_3d	*point_3d_proj;
    int         size_x;

    mat_proj = fdf->mat_proj;
    size_x = fdf->mat_3d_proj->size_x;
	point_3d = fdf->mat_3d->array[y * size_x + x];
    point_3d_proj = fdf->mat_3d_proj->array[y * size_x + x];
    if (point_3d == NULL)
    {
        free(point_3d_proj);
        fdf->mat_3d_proj->array[y * size_x + x] = NULL;
        return ;
    }

    //NUL mais fixe...
    if (point_3d_proj != NULL);
        free(point_3d_proj);

    point_3d_proj = new_point_3d(fdf, 0, 0, 0);

    point_3d_proj->x = mat_proj->array[0]->x * point_3d->x;
    point_3d_proj->y = mat_proj->array[5]->x * point_3d->y;
    point_3d_proj->z = mat_proj->array[10]->x * point_3d->z + mat_proj->array[11]->x * point_3d->z;
    point_3d_proj->w = mat_proj->array[14]->x * point_3d->z;
    fdf->mat_3d_proj->array[y * size_x + x] = point_3d_proj;
}
