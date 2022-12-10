/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:24:48 by tquere            #+#    #+#             */
/*   Updated: 2022/12/10 17:17:20 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	key_move(int keycode, t_fdf *fdf)
{	
	if (keycode == Key_W)
		fdf->r_x += INC_ROT;
	if (keycode == Key_S)
		fdf->r_x -= INC_ROT;
	if (keycode == Key_D)
		fdf->r_y += INC_ROT;
	if (keycode == Key_A)
		fdf->r_y -= INC_ROT;
	if (keycode == Key_J)
		fdf->r_z += INC_ROT;
	if (keycode == Key_U)
		fdf->r_z -= INC_ROT;
	if (keycode == Key_Right)
		fdf->t_x += fdf->map->max_x * 0.1 + 1;
	if (keycode == Key_Left)
		fdf->t_x -= fdf->map->max_x * 0.1 + 1;
	if (keycode == Key_Up)
		fdf->t_y -= fdf->map->max_y * 0.1 + 1;
	if (keycode == Key_Down)
		fdf->t_y += fdf->map->max_y * 0.1 + 1;
	if (keycode == Key_I)
		fdf->t_z += fdf->max_coord * 1.5 + 1;
	if (keycode == Key_K)
		fdf->t_z -= fdf->max_coord * 1.5 + 1;
}

static void	key_zoom(int keycode, t_fdf *fdf)
{
	double	inc;

	inc = INC_FOV;
	if (keycode == Key_Minus)
		fdf->cam->fov -= inc;
	if (keycode == Key_Plus)
		fdf->cam->fov += inc;
	if (fdf->cam->fov > 3.14)
		fdf->cam->fov = 3.14;
	if (fdf->cam->fov < 0)
		fdf->cam->fov = 0.05;
	if (keycode == Key_Space)
		reset(fdf);
}

static int	set_hook(int keycode, t_fdf *fdf)
{
	if (keycode == Key_Escape)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		free_exit(fdf, 0);
	}
	key_move(keycode, fdf);
	key_zoom(keycode, fdf);
	if (fdf->t_x > INT_MAX || fdf->r_x < INT_MIN)
		fdf->t_x = 0;
	if (fdf->t_y > INT_MAX || fdf->r_y < INT_MIN)
		fdf->t_y = 0;
	if (fdf->t_z > INT_MAX || fdf->r_z < INT_MIN)
		fdf->t_z = 0;
	if (fdf->r_x > INT_MAX || fdf->r_x < INT_MIN)
		fdf->r_x = 0;
	if (fdf->r_y > INT_MAX || fdf->r_y < INT_MIN)
		fdf->r_y = 0;
	if (fdf->r_z > INT_MAX || fdf->r_z < INT_MIN)
		fdf->r_z = 0;
	update(fdf);
	return (0);
}

static int	quit(t_fdf *fdf)
{
	if (fdf->mlx && fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	free_exit(fdf, 0);
	return (0);
}

void	init_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, RES_X, RES_Y, WIN_NAME);
	mlx_key_hook(fdf->win, set_hook, fdf);
	mlx_hook(fdf->win, 17, 1L << 0, quit, fdf);
}
