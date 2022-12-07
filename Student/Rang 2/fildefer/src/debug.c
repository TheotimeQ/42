/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:55:55 by tquere            #+#    #+#             */
/*   Updated: 2022/12/07 23:35:49 by zelinsta         ###   ########.fr       */
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
