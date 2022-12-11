/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:11:13 by tquere            #+#    #+#             */
/*   Updated: 2022/12/11 12:32:54 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_exit(t_fdf *fdf, int error_code)
{	
	free_matrice(fdf->mat_3d);
	free_matrice(fdf->mat_3d_proj);
	free_matrice(fdf->mat_proj);
	free_matrice(fdf->mat_rot);
	free(fdf->map);
	if (fdf->img != NULL)
		mlx_destroy_image(fdf->mlx, fdf->img);
	free(fdf->cam);
	free(fdf);
	exit(error_code);
}

void	init_cam(t_fdf *fdf)
{
	fdf->cam = malloc(sizeof(t_cam));
	if (fdf == NULL)
	{
		ft_printf(2, "Error: malloc cam\n");
		free_exit(fdf, 1);
	}
	fdf->cam->fov = 0.05;
	fdf->cam->z_min = 0;
	fdf->cam->z_max = 0;
}

void	init_map(t_fdf *fdf)
{
	fdf->map = malloc(sizeof(t_map));
	if (fdf == NULL)
	{
		ft_printf(2, "Error: malloc map\n");
		free_exit(fdf, 1);
	}
	fdf->map->max_x = 0;
	fdf->map->max_y = 0;
	fdf->map->min_z = 0;
	fdf->map->max_z = 0;
}

t_fdf	*init_fdf(void)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (fdf == NULL)
	{
		ft_printf(2, "Error: malloc fdf\n");
		exit(1);
	}
	fdf->map = NULL;
	fdf->cam = NULL;
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->img = NULL;
	fdf->mat_3d = NULL;
	fdf->mat_3d_proj = NULL;
	fdf->mat_proj = NULL;
	fdf->mat_rot = NULL;
	fdf->res_x = RES_X;
	fdf->res_y = RES_Y;
	fdf->ratio = RES_X / RES_Y;
	init_map(fdf);
	init_cam(fdf);
	return (fdf);
}
