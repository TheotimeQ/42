/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:11:13 by tquere            #+#    #+#             */
/*   Updated: 2022/12/07 18:35:45 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_exit(t_fdf *fdf, int error_code)
{	
	//free matrice 3D
	free_matrice(fdf->mat_3d);

	//free matrice 3D proj
	free_matrice(fdf->mat_3d_proj);

	//free matrice proj
	free_matrice(fdf->mat_proj);

	//free matrice rot
	free_matrice(fdf->mat_rot);

	//free vector
	free(fdf->u_x);
	free(fdf->u_y);
	free(fdf->u_z);

	//free objet map
	if (fdf->map)
		free(fdf->map->values);
	free(fdf->map);

	//free image 
	if (fdf->img != NULL)
		mlx_destroy_image(fdf->mlx, fdf->img);

	//free cam
	free(fdf->cam);

	//free fdf
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
	fdf->cam->r_x = 0;
	fdf->cam->r_y = 0;
	fdf->cam->r_z = 00;
	fdf->cam->fov = 0.1;
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
	fdf->mat_3d_proj = NULL;
	fdf->mat_proj = NULL;
	fdf->mat_rot = NULL;
	fdf->res_x = RES_X;
	fdf->res_y = RES_Y;
	fdf->ratio = RES_X / RES_Y;
	fdf->draw_witdh = DRAW_WITDH;
	fdf->u_x = NULL;
	fdf->u_y = NULL;
	fdf->u_z = NULL;
	init_map(fdf);
	init_cam(fdf);
	return (fdf);
}
