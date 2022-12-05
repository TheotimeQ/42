#include "fdf.h"

void init_mat_proj(t_fdf *fdf)
{
    int     x;
    int     y;

    y = 0;
    while (y < 4)
    {   
        x = 0;
        while (x < 4)
        {   
            fdf->mat_proj[y * 4 + x] = 0;
            x++;
        }    
        y++;
    }
}

void get_mat_proj(t_fdf *fdf)
{ 
    fdf->mat_proj[0 * 4 + 0] = fdf->ratio * 1 / tan(fdf->cam->fov / 2);
    fdf->mat_proj[1 * 4 + 1] = 1 / tan(fdf->cam->fov / 2);
    fdf->mat_proj[2 * 4 + 2] = fdf->cam->z_max / (fdf->cam->z_max - fdf->cam->z_min);
    fdf->mat_proj[2 * 4 + 3] = (-fdf->cam->z_max * fdf->cam->z_min)  / (fdf->cam->z_max - fdf->cam->z_min);
    fdf->mat_proj[3 * 4 + 2] = 1;
}

void    apply_proj(t_fdf *fdf)
{
    int     x;
    int     y;

    y = 0;
    while (y < fdf->map->max_y)
    {   
        x = 0;
        while (x < fdf->map->max_x)
        {   
            matrice_product(fdf, fdf->mat_3D[y * fdf->map->max_x + x]);
            x++;
        }    
        y++;
    }
}

void    scale_to_res(t_fdf *fdf)
{
    int     x;
    int     y;
    double  w;
    double  scaled_x;
    double  scaled_y;
    double  scaled_z;

    y = 0;
    while (y < fdf->map->max_y)
    {   
        x = 0;
        while (x < fdf->map->max_x)
        {   
            w = fdf->mat_3D[y * fdf->map->max_x + x]->w;
            scaled_x =  fdf->mat_3D[y * fdf->map->max_x + x]->x;
            scaled_y =  fdf->mat_3D[y * fdf->map->max_x + x]->y;
            scaled_z =  fdf->mat_3D[y * fdf->map->max_x + x]->z;
            scaled_x = (((scaled_x / w) + 1) / 2) * fdf->res_x;
            scaled_y = (((scaled_y / w) + 1) / 2) * fdf->res_y;
            scaled_z = scaled_z / w;
            fdf->mat_3D[y * fdf->map->max_x + x]->x = scaled_x;
            fdf->mat_3D[y * fdf->map->max_x + x]->y = scaled_y;
            fdf->mat_3D[y * fdf->map->max_x + x]->z = scaled_z;
            x++;
        }    
        y++;
    }
}

void    matrice_product(t_fdf *fdf, t_point_3D *point_3D)
{
    t_point_3D temp_point;
    int         y;

    temp_point.x = fdf->mat_proj[0] * point_3D->x;
    temp_point.x += fdf->mat_proj[1] * point_3D->y;
    temp_point.x += fdf->mat_proj[2] * point_3D->z;
    temp_point.x += fdf->mat_proj[3] * point_3D->w;
    temp_point.y = fdf->mat_proj[4] * point_3D->x;
    temp_point.y += fdf->mat_proj[5] * point_3D->y;
    temp_point.y += fdf->mat_proj[6] * point_3D->z;
    temp_point.y += fdf->mat_proj[7] * point_3D->w;
    temp_point.z = fdf->mat_proj[8] * point_3D->x;
    temp_point.z += fdf->mat_proj[9] * point_3D->y;
    temp_point.z += fdf->mat_proj[10] * point_3D->z;
    temp_point.z += fdf->mat_proj[11] * point_3D->w;
    temp_point.w = fdf->mat_proj[12] * point_3D->x;
    temp_point.w += fdf->mat_proj[13] * point_3D->y;
    temp_point.w += fdf->mat_proj[14] * point_3D->z;
    temp_point.w += fdf->mat_proj[15] * point_3D->w;   

    point_3D->x = temp_point.x;
    point_3D->y = temp_point.y;
    point_3D->z = temp_point.z;
    point_3D->w = temp_point.w;
}

