/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_moove_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 12:49:14 by tquere            #+#    #+#             */
/*   Updated: 2022/12/11 12:50:04 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_move(int keycode, t_fdf *fdf)
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

void	key_zoom(int keycode, t_fdf *fdf)
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