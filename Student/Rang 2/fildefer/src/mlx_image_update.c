#include "fdf.h"

void    update_img(t_fdf *fdf)
{   
    if (fdf->img != NULL)
        mlx_destroy_image(fdf->mlx, fdf->img);
    mlx_clear_window(fdf->mlx, fdf->win);
    fdf->img = mlx_new_image(fdf->mlx, fdf->res_x, fdf->res_y);
    fill_img(fdf);
    // mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

void    fill_img(t_fdf *fdf)
{
    int     x;
    int     y;

    double  x_point;
    double  y_point;

    y = 0;
    while (y < fdf->map->max_y)
    {   
        x = 0;
        while (x < fdf->map->max_x)
        {   
            x_point = fdf->mat_3D[y * fdf->map->max_x + x]->x;
            y_point = fdf->mat_3D[y * fdf->map->max_x + x]->y;
            mlx_pixel_put(fdf->mlx, fdf->win, x_point, y_point, 0x39FF14);
            x++;
        }    
        y++;
    }
}

