/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_rotation_vector.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:21:47 by zelinsta          #+#    #+#             */
/*   Updated: 2022/12/07 19:00:42 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    rotate_vector(t_fdf *fdf, t_point_3d *vector)
{
    point_3d = rot_point(fdf, point_3d, fdf->mat_rot);
    fdf->u_x = normalise_vector(fdf->cam->r_x, vector);
    
    //Rotate le vecteur 
    //Normalise le vecteur
}

static t_point_3d*    normalise_vector(double rot_xyz, t_point_3d *vector)
{   
    double len;

    len = sqrt(vector->x + vector->y + vector->z); 
    vector->x = vector->x / len;
    vector->y = vector->y / len;
    vector->z = vector->z / len;
    vector->w = rot_xyz;
    return (vector);
}

void    get_rotate_vector(t_fdf *fdf)
{   
    t_point_3d *vector;
    
    if (fdf->u_x != NULL)
        free(fdf->u_x);
    vector = new_point_3d(fdf, 1, 0, 0);
    fdf->u_x = normalise_vector(fdf->cam->r_x, vector);

    if (fdf->u_y != NULL)
        free(fdf->u_y);
    vector = new_point_3d(fdf, 0, 1, 0);
    fdf->u_y = normalise_vector(fdf->cam->r_y, vector);

    if (fdf->u_z != NULL)
        free(fdf->u_z);
    vector = new_point_3d(fdf, 0, 0, 1);
    fdf->u_z = normalise_vector(fdf->cam->r_z, vector);
}