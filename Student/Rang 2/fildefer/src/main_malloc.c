/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:11:13 by tquere            #+#    #+#             */
/*   Updated: 2022/12/06 19:59:19 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_exit(t_fdf *fdf, int error_code)
{	
	if (fdf->img != NULL)
		mlx_destroy_image(fdf->mlx, fdf->img);
	free(fdf->mat_proj);
	free(fdf->mat_rot_x);
	free(fdf->mat_rot_y);
	free(fdf->mat_rot_z);
	if (fdf->mat_3d)
		free_matrice_3d(fdf, fdf->mat_3d);
	free(fdf->mat_3d);
	if (fdf->mat_3d_proj)
		free_matrice_3d(fdf, fdf->mat_3d_proj);
	free(fdf->mat_3d_proj);
	if (fdf->map)
		free(fdf->map->values);
	free(fdf->map);
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
	fdf->cam->t_x = 0;
	fdf->cam->t_y = 0;
	fdf->cam->t_z = 0;
	fdf->cam->r_x = -3.14;
	fdf->cam->r_y = 0;
	fdf->cam->r_z = 0;
	fdf->cam->fov = 2.27;
	fdf->cam->z_min = -10;
	fdf->cam->z_max = 10;
}

void	init_map(t_fdf *fdf)
{
	fdf->map = malloc(sizeof(t_map));
	if (fdf == NULL)
	{
		ft_printf(2, "Error: malloc map\n");
		free_exit(fdf, 1);
	}
	fdf->map->values = NULL;
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
	fdf->mat_proj = NULL;
	fdf->mat_trans = NULL;
	fdf->mat_rot_x = NULL;
	fdf->mat_rot_y = NULL;
	fdf->mat_rot_z = NULL;
	fdf->res_x = RES_X;
	fdf->res_y = RES_Y;
	fdf->ratio = RES_X / RES_Y;
	fdf->draw_witdh = 5;
	init_map(fdf);
	init_cam(fdf);
	return (fdf);
}

void	malloc_map_value(t_fdf *fdf)
{
	fdf->map->values = malloc(sizeof(int) * fdf->map->max_y * fdf->map->max_x);
	if (fdf == NULL)
	{
		ft_printf(2, "Error: malloc map values\n");
		free_exit(fdf, 1);
	}
}

