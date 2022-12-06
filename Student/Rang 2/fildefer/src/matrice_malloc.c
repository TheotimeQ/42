/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:16:28 by tquere            #+#    #+#             */
/*   Updated: 2022/12/06 14:10:08 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point_3d	**new_matrice_3d(t_fdf *fdf)
{	
	t_point_3d	**mat;

	mat = malloc(sizeof(t_point_3d *) * fdf->map->max_x * fdf->map->max_y);
	if (mat == NULL)
	{
		ft_printf(2, "Error: malloc matrice points 3D\n");
		free_exit(fdf, 1);
	}
	return (mat);
}

void	free_matrice_3d(t_fdf *fdf, t_point_3d **mat)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map->max_y)
	{
		x = 0;
		while (x < fdf->map->max_x)
		{
			free(mat[y * fdf->map->max_x + x]);
			x++;
		}
		y++;
	}
}

void	malloc_matrice_proj(t_fdf *fdf)
{
	fdf->mat_proj = malloc(sizeof(double) * 4 * 4);
	if (fdf->mat_proj == NULL)
	{
		ft_printf(2, "Error: malloc matrice proj\n");
		free_exit(fdf, 1);
	}
}

