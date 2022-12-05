#include "fdf.h"

void	free_exit(t_fdf *fdf, int error_code)
{	
	if (fdf->img != NULL)
        mlx_destroy_image(fdf->mlx, fdf->img);
	free(fdf->mat_proj);
	if (fdf->mat_3D)
		free_matrice_3D(fdf);
	free(fdf->mat_3D);
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
		free_exit(fdf,1);
	}
	fdf->cam->x = 0;
	fdf->cam->y = 0;
	fdf->cam->z = 0;
	fdf->cam->rx = 0;
	fdf->cam->ry = 0;
	fdf->cam->rz = 0;
	fdf->cam->fov = 2.5;
	fdf->cam->z_min = -5;
	fdf->cam->z_max = 5;
}

void	init_map(t_fdf *fdf)
{
	fdf->map = malloc(sizeof(t_map));
	if (fdf == NULL)
	{
		ft_printf(2, "Error: malloc map\n");
		free_exit(fdf,1);
	}
	fdf->map->values = NULL;
	fdf->map->max_x = 0;
	fdf->map->max_y = 0;
	fdf->map->min_z = 0;
	fdf->map->max_z = 0;
}

t_fdf	*init_fdf(void)
{
	t_fdf *fdf;

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
	fdf->mat_3D = NULL;
	fdf->mat_proj = NULL;
	fdf->res_x = RES_X;
	fdf->res_y = RES_Y;
	fdf->ratio = RES_X / RES_Y;
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
		free_exit(fdf,1);
	}
}

