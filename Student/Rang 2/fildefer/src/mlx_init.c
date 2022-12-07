/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:24:48 by tquere            #+#    #+#             */
/*   Updated: 2022/12/07 23:22:43 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	key_rotation(int keycode, t_fdf *fdf)
{	
	double	inc; 

	inc = INC_ROT;
	if (keycode == Key_W)
		fdf->r_x += inc;
	if (keycode == Key_S)
		fdf->r_x -= inc;
	if (keycode == Key_D)
		fdf->r_y += inc;
	if (keycode == Key_A)
		fdf->r_y -= inc;
	if (keycode == Key_J)
		fdf->r_z += inc;
	if (keycode == Key_U)
		fdf->r_z -= inc;
}

static void	key_move(int keycode, t_fdf *fdf)
{
	double	inc; 

	inc = INC_TRANS;
	if (keycode == Key_Right)
		fdf->t_x += inc;
	if (keycode == Key_Left)
		fdf->t_x -= inc;
	if (keycode == Key_Up)
		fdf->t_y -= inc;
	if (keycode == Key_Down)
		fdf->t_y += inc;
	if (keycode == Key_I)
		fdf->t_z += inc;
	if (keycode == Key_K)
		fdf->t_z -= inc;
}

static void	key_zoom(int keycode, t_fdf *fdf)
{
	double	inc; 

	inc = INC_ROT;
	if (keycode == Key_Minus)
		fdf->cam->fov -= inc;
	if (keycode == Key_Plus)
		fdf->cam->fov += inc;
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
	update(fdf);
	return (0);
}

void	init_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, RES_X, RES_Y, WIN_NAME);
	mlx_key_hook(fdf->win, set_hook, fdf);
}
