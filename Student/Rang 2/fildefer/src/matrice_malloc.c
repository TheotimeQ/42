/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:16:28 by tquere            #+#    #+#             */
/*   Updated: 2022/12/11 12:33:02 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrice(t_matrice *matrice)
{
	int	x;
	int	y;

	if (matrice == NULL)
		return ;
	if (matrice->array == NULL)
		free(matrice);
	y = 0;
	while (y < matrice->size_y)
	{
		x = 0;
		while (x < matrice->size_x)
		{
			free(matrice->array[y * matrice->size_x + x]);
			x++;
		}
		y++;
	}
	free(matrice->array);
	free(matrice);
}

static void	init_mat(t_matrice *matrice)
{
	int	x;
	int	y;

	y = 0;
	while (y < matrice->size_y)
	{
		x = 0;
		while (x < matrice->size_x)
		{
			matrice->array[y * matrice->size_x + x] = NULL;
			x++;
		}
		y++;
	}
}

t_matrice	*new_matrice(t_fdf *fdf, int size_x, int size_y)
{	
	t_matrice	*matrice;

	matrice = malloc(sizeof(t_point_3d *) * size_x * size_y);
	if (matrice == NULL)
	{
		ft_printf(2, "Error: malloc new_matrice\n");
		free_exit(fdf, 1);
	}
	matrice->size_x = size_x;
	matrice->size_y = size_y;
	matrice->array = malloc(sizeof(t_point_3d *) * size_x * size_y);
	if (matrice->array == NULL)
	{
		ft_printf(2, "Error: malloc matrice array\n");
		free_exit(fdf, 1);
	}
	init_mat(matrice);
	return (matrice);
}
