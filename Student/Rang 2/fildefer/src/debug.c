/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:55:55 by tquere            #+#    #+#             */
/*   Updated: 2023/01/08 11:08:58 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_matrice(t_matrice *matrice)
{
	int			x;
	int			y;
	t_point_3d	*point;

	if (!matrice)
		return ;
	y = 0;
	while (y < matrice->size_y)
	{
		x = 0;
		while (x < matrice->size_x)
		{	
			point = matrice->array[y * matrice->size_x + x];
			if (point != NULL)
				printf("%.1f | ",point->x);
			else
				printf(" NULL |");
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}

void	print_infos(t_fdf *fdf)
{
	ft_printf(2, "\n\n--------------------------------------\n");
	ft_printf(2, "x:%d y:%d min_z:%d max_z:%d\n\n",fdf->map->max_x, fdf->map->max_y, fdf->map->min_z, fdf->map->max_z);
	printf("x_pos:%.2f y_pos:%.2f z_pos:%.2f fov:%.2f\n\n", fdf->t_x, fdf->t_y, fdf->t_z, fdf->cam->fov);
	printf("x_rot:%.2f y_rot:%.2f z_rot:%.2f \n\n", fdf->r_x, fdf->r_y, fdf->r_z);
	ft_printf(1, "MAT 3D \n");
	print_matrice(fdf->mat_3d);
	ft_printf(1, "MAT 3D PROJ\n");
	print_matrice(fdf->mat_3d_proj);
	ft_printf(1, "MAT PROJ\n");
	print_matrice(fdf->mat_proj);
	ft_printf(1, "MAT ROT\n");
	print_matrice(fdf->mat_rot);
}
