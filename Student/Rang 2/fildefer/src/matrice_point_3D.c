#include "fdf.h"

static t_point_3D  *new_point_3D(t_fdf *fdf, double x, double y,double z, double w)
{
    t_point_3D *point_3D;

    point_3D = malloc(sizeof(t_point_3D));
    if (point_3D == NULL)
	{
		ft_printf(2, "Error: malloc point_3D\n");
		free_exit(fdf,1);
	}
    point_3D->x = x;
    point_3D->y = y;
    point_3D->z = z;
    point_3D->w = w;
    return (point_3D);
}

void init_mat_3D(t_fdf *fdf)
{
    int     x;
    int     y;

    y = 0;
    while (y < fdf->map->max_y)
    {   
        x = 0;
        while (x < fdf->map->max_x)
        {   
            fdf->mat_3D[y * fdf->map->max_x + x] = NULL;
            x++;
        }    
        y++;
    }
}

static void get_value_mat_3D(t_fdf *fdf)
{
    t_point_3D      *point_3D;
    int             x;
    int             y;
    int             z;

    y = 0;
    while (y < fdf->map->max_y)
    {   
        x = 0;
        while (x < fdf->map->max_x)
        {   
            z = fdf->map->values[y * fdf->map->max_x + x];
            if (fdf->mat_3D[y * fdf->map->max_x + x] == NULL)
            {
                point_3D = new_point_3D(fdf, x, y, z, 1);
                fdf->mat_3D[y * fdf->map->max_x + x] = point_3D;
            }
            else
            {
                fdf->mat_3D[y * fdf->map->max_x + x]->x = x;
                fdf->mat_3D[y * fdf->map->max_x + x]->y = y;
                fdf->mat_3D[y * fdf->map->max_x + x]->z = z;
                fdf->mat_3D[y * fdf->map->max_x + x]->w = 1;
            }
            x++;
        }    
        y++;
    }
}

void update_mat_3D(t_fdf *fdf)
{
    get_value_mat_3D(fdf);
    get_mat_proj(fdf);

	print_mat_3D(fdf);
	print_mat_proj(fdf);

    apply_proj(fdf);
    print_mat_3D(fdf);

    scale_to_res(fdf);
    print_mat_3D(fdf);
}