/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:36:54 by tquere            #+#    #+#             */
/*   Updated: 2023/01/31 12:10:55 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update(t_fdf *fdf)
{	
	int			x;
	int			y;

	get_mat_proj(fdf);
	get_mat_rot(fdf);
	y = 0;
	while (y < fdf->mat_3d_proj->size_y)
	{
		x = 0;
		while (x < fdf->mat_3d_proj->size_x)
		{	
			if (fdf->mat_3d->array[y * fdf->mat_3d->size_x + x])
			{
				cpy_point_3d(fdf, x, y);
				center_map(fdf, x, y);
				rotate(fdf, x, y);
				translate(fdf, x, y);
				project(fdf, x, y);
				scale(fdf, x, y);
			}
			x++;
		}
		y++;
	}
	// print_infos(fdf);
	update_img(fdf);
}

void	reset(t_fdf *fdf)
{	
	fdf->cam->z_max = fdf->map->max_z;
	fdf->cam->fov = 0.05;
	fdf->cam->z_min = 0;
	fdf->cam->z_max = 10;
	fdf->r_x = 2.4;
	fdf->r_y = 0.6;
	fdf->r_z = 0.6;
	fdf->t_x = -0.2;
	fdf->t_y = -1;
	fdf->t_z = 2;
	if (fdf->map->min_z < 0)
		fdf->t_z = -fdf->map->min_z;
	if (fdf->map->min_z > 0)
		fdf->t_z = 0;
	if (fdf->map->max_z >= fdf->map->max_x
		&& fdf->map->max_z >= fdf->map->max_y)
		fdf->max_coord = fdf->map->max_z;
	else if (fdf->map->max_x >= fdf->map->max_z
		&& fdf->map->max_x >= fdf->map->max_y)
		fdf->max_coord = fdf->map->max_x;
	else if (fdf->map->max_y >= fdf->map->max_x
		&& fdf->map->max_y >= fdf->map->max_z)
		fdf->max_coord = fdf->map->max_y;
	fdf->t_z += fdf->max_coord;
	fdf->t_z = fdf->t_z * 27 + 2;
}

int	main(int argc, char **argv)
{	
	t_fdf	*fdf;

	fdf = init_fdf();
	check_args(fdf, argc, argv);
	fdf->mat_3d = new_matrice(fdf, fdf->map->max_x, fdf->map->max_y);
	parse_map(fdf);
	fdf->mat_3d_proj = new_matrice(fdf, fdf->map->max_x, fdf->map->max_y);
	fdf->mat_proj = new_matrice(fdf, 4, 4);
	fdf->mat_rot = new_matrice(fdf, 3, 3);
	init_mlx(fdf);
	reset(fdf);
	update(fdf);
	mlx_loop(fdf->mlx);
	free_exit(fdf, 0);
}
