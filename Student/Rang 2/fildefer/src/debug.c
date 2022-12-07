/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:55:55 by tquere            #+#    #+#             */
/*   Updated: 2022/12/07 18:48:21 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map->max_y)
	{
		x = 0;
		ft_printf(1, "\n");
		while (x < fdf->map->max_x)
		{
			ft_printf(1, "%d ", fdf->map->values[y * fdf->map->max_x + x]);
			x++;
		}
		y++;
	}
}

void	print_matrice(t_matrice *matrice)
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
			if ( point != NULL)
				printf("%.1f %.1f %.1f %.1f | ", point->x, point->y, point->z, point->w);
			else
				printf(" NULL |");
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}

void	print_u_vector(t_fdf *fdf)
{	
	if (fdf->u_x != NULL)
		printf("u_x: %.1f %.1f %.1f %.3f\n", fdf->u_x->x, fdf->u_x->y, fdf->u_x->z, sqrt(fdf->u_x->x + fdf->u_x->y + fdf->u_x->z));
	else
		printf("u_x: NULL\n");
	if (fdf->u_y != NULL)
		printf("u_y: %.1f %.1f %.1f %.3f\n", fdf->u_y->x, fdf->u_y->y, fdf->u_y->z, sqrt(fdf->u_y->x + fdf->u_y->y + fdf->u_y->z));
	else
		printf("u_y: NULL\n");
	if (fdf->u_z != NULL)
		printf("u_z: %.1f %.1f %.1f %.3f\n", fdf->u_z->x, fdf->u_z->y, fdf->u_z->z, sqrt(fdf->u_z->x + fdf->u_z->y + fdf->u_z->z));
	else
		printf("u_z: NULL\n");
	printf("\n");
}
