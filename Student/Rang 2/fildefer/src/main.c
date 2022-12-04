/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:36:54 by tquere            #+#    #+#             */
/*   Updated: 2022/12/04 16:31:59 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{	
	(void)argc;
	(void)argv;
	ft_printf(1, "TEST\n");

	void	*init_ptr;
	void	*wind_ptr;

	init_ptr = mlx_init();
	wind_ptr = mlx_new_window(init_ptr, 100, 100, "COUCOU LOUIS");
	mlx_loop (init_ptr);
	
}



void	*mlx_init();
void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);

void	*mlx_new_image(void *mlx_ptr,int width,int height);
int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,int *size_line, int *endian);

int		mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
int		mlx_clear_window(void *mlx_ptr, void *win_ptr);

int		mlx_destroy_image(void *mlx_ptr, void *img_ptr);
int		mlx_destroy_window(void *mlx_ptr, void *win_ptr);

//HOOK
int		mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int		mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int		mlx_expose_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int		mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
int		mlx_loop (void *mlx_ptr);
int		mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);

//OTHER
int		mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color,char *string);
void	*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,int *width, int *height);
void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);




int	mlx_do_key_autorepeatoff(void *mlx_ptr);
int	mlx_do_key_autorepeaton(void *mlx_ptr);
int	mlx_do_sync(void *mlx_ptr);