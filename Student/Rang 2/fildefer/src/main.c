/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:36:54 by tquere            #+#    #+#             */
/*   Updated: 2022/12/05 22:23:58 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	update(t_fdf *fdf)
{	
	ft_printf(2, "\n\n--------------------------------------\n");
	ft_printf(2, "x:%d y:%d min_z:%d max_z:%d\n\n",fdf->map->max_x, fdf->map->max_y, fdf->map->min_z, fdf->map->max_z);
	printf("cam_x:%.2f cam_y:%.2f cam_z:%.2f fov:%.2f\n\n",fdf->cam->x, fdf->cam->y, fdf->cam->z, fdf->cam->fov);
	
	//update 3D matrice
	update_mat_3D(fdf);
	
	//Creer l'image basé sur les points
	update_img(fdf);
}

int	main(int argc, char **argv)
{	
	t_fdf *fdf;

	//Setup Env
	fdf = init_fdf();
	
	//Map parsing
	check_args(fdf, argc, argv);
	parse_map(fdf);
	print_map(fdf);

	//init mlx
	init_mlx(fdf);

	//Init mat 3D
	malloc_matrice_3D(fdf);
	init_mat_3D(fdf);

	//init mat proj
	malloc_matrice_proj(fdf);
	init_mat_proj(fdf);

	// fdf->cam->z_max = fdf->map->max_z;
	// fdf->cam->z_min = fdf->map->min_z;

	//Creer l'image à afficher
	update(fdf);

	//demare a loop mlx
	start_mlx(fdf);

	free_exit(fdf,0);
}



// void	*mlx_init();
// void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);

// void	*mlx_new_image(void *mlx_ptr,int width,int height);
// int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
// char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,int *size_line, int *endian);

// int		mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
// int		mlx_clear_window(void *mlx_ptr, void *win_ptr);

// int		mlx_destroy_image(void *mlx_ptr, void *img_ptr);
// int		mlx_destroy_window(void *mlx_ptr, void *win_ptr);

// //HOOK
// int		mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);
// int		mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
// int		mlx_expose_hook (void *win_ptr, int (*funct_ptr)(), void *param);
// int		mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
// int		mlx_loop (void *mlx_ptr);
// int		mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);

// //OTHER
// int		mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color,char *string);
// void	*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,int *width, int *height);
// void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);

// int	mlx_do_key_autorepeatoff(void *mlx_ptr);
// int	mlx_do_key_autorepeaton(void *mlx_ptr);
// int	mlx_do_sync(void *mlx_ptr);