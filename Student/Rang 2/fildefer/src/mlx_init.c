/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:24:48 by tquere            #+#    #+#             */
/*   Updated: 2022/12/06 20:04:58 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	key_rotation(int keycode, t_fdf *fdf)
{
	if (keycode == Key_W)
		fdf->cam->r_x += 0.12;
	if (keycode == Key_S)
		fdf->cam->r_x -= 0.12;
	if (keycode == Key_D)
		fdf->cam->r_y += 0.12;
	if (keycode == Key_A)
		fdf->cam->r_y -= 0.12;
	if (keycode == Key_J)
		fdf->cam->r_z += 0.12;
	if (keycode == Key_U)
		fdf->cam->r_z -= 0.12;
	if (keycode == Key_W)
		fdf->x_rot += 0.12;
	if (keycode == Key_S)
		fdf->x_rot -= 0.12;
	if (keycode == Key_D)
		fdf->y_rot += 0.12;
	if (keycode == Key_A)
		fdf->y_rot -= 0.12;
	if (keycode == Key_J)
		fdf->z_rot += 0.12;
	if (keycode == Key_U)
		fdf->z_rot -= 0.12;
}

static void	key_move(int keycode, t_fdf *fdf)
{
	if (keycode == Key_Right)
		fdf->cam->t_x -= 0.25;
	if (keycode == Key_Left)
		fdf->cam->t_x += 0.25;
	if (keycode == Key_Up)
		fdf->cam->t_y -= 0.25;
	if (keycode == Key_Down)
		fdf->cam->t_y += 0.25;
	if (keycode == Key_I)
		fdf->cam->t_z += 0.25;
	if (keycode == Key_K)
		fdf->cam->t_z -= 0.25;
	if (keycode == Key_Right)
		fdf->x_pos += 0.25;
	if (keycode == Key_Left)
		fdf->x_pos -= 0.25;
	if (keycode == Key_Up)
		fdf->y_pos -= 0.25;
	if (keycode == Key_Down)
		fdf->y_pos += 0.25;
	if (keycode == Key_I)
		fdf->z_pos += 0.25;
	if (keycode == Key_K)
		fdf->z_pos -= 0.25;
}

static void	key_zoom(int keycode, t_fdf *fdf)
{
	if (keycode == Key_Minus)
		fdf->cam->fov -= 0.12;
	if (keycode == Key_Plus)
		fdf->cam->fov += 0.12;
	if (fdf->cam->fov > 3.14)
		fdf->cam->fov = 3.14;
	if (fdf->cam->fov < 0)
		fdf->cam->fov = 0;
}

static int	set_hook(int keycode, t_fdf *fdf)
{
	ft_printf(1, "Key down: %d \n", keycode);
	if (keycode == Key_Escape)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		free_exit(fdf, 0);
	}
	key_rotation(keycode, fdf);
	key_move(keycode, fdf);
	key_zoom(keycode, fdf);

	update_mat_3D_proj(fdf);
	update_img(fdf);
	return (0);
}

void	init_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, RES_X, RES_Y, WIN_NAME);
	mlx_key_hook(fdf->win, set_hook, fdf);
}
