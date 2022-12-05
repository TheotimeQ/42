#include "fdf.h"

void    print_map(t_fdf *fdf)
{   
    int x;
    int y;

    y = 0;
    while (y < fdf->map->max_y)
    {   
        x = 0;
        while (x < fdf->map->max_x)
        {
            ft_printf(1, "%d ", fdf->map->values[y * fdf->map->max_x + x]);
            x++;
        }    
        ft_printf(1, "\n"); 
        y++;
    }
    ft_printf(1, "\n"); 
}

void    print_mat_3D(t_fdf *fdf)
{   
    int x;
    int y;
    double x_pt;
    double y_pt;
    double z_pt;
    double w_pt;

    y = 0;
    while (y < fdf->map->max_y)
    {   
        x = 0;
        while (x < fdf->map->max_x)
        {   
            if (fdf->mat_3D[y * fdf->map->max_x + x] != NULL)
            {
                x_pt = fdf->mat_3D[y * fdf->map->max_x + x]->x;
                y_pt = fdf->mat_3D[y * fdf->map->max_x + x]->y;
                z_pt = fdf->mat_3D[y * fdf->map->max_x + x]->z;
                w_pt = fdf->mat_3D[y * fdf->map->max_x + x]->w;
                printf("%.0f %.0f %.0f %.0f | ",x_pt, y_pt, z_pt, w_pt);
            }
            else
                printf("NULL | ");
            x++;
        }    
        printf("\n"); 
        y++;
    }
    ft_printf(1, "\n"); 
}

void    print_mat_proj(t_fdf *fdf)
{   
    int x;
    int y;

    y = 0;
    while (y < 4)
    {   
        x = 0;
        while (x < 4)
        {   
            printf("%.2f | ",fdf->mat_proj[y * 4 + x]);
            x++;
        }    
        printf("\n"); 
        y++;
    }
    ft_printf(1, "\n"); 
}
