#include "fdf.h"

void    malloc_matrice_3D(t_fdf *fdf)
{
    fdf->mat_3D = malloc(sizeof(t_point_3D*) * fdf->map->max_x * fdf->map->max_y);
    if (fdf->mat_3D  == NULL)
	{
		ft_printf(2, "Error: malloc matrice points 3D\n");
		free_exit(fdf,1);
	}
}

void free_matrice_3D(t_fdf *fdf)
{
    int     x;
    int     y;

    y = 0;
    while (y < fdf->map->max_y)
    {   
        x = 0;
        while (x < fdf->map->max_x)
        {   
            free(fdf->mat_3D[y * fdf->map->max_x + x]);
            x++;
        }    
        y++;
    }
}

void    malloc_matrice_proj(t_fdf *fdf)
{
    fdf->mat_proj = malloc(sizeof(double) * 4 * 4);
    if (fdf->mat_proj  == NULL)
	{
		ft_printf(2, "Error: malloc matrice proj\n");
		free_exit(fdf,1);
	}
}

