/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:24:48 by tquere            #+#    #+#             */
/*   Updated: 2022/12/11 12:49:40 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static int	expose(t_fdf *fdf)
{
	update(fdf);
	return (0);
}

void	init_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, RES_X, RES_Y, WIN_NAME);
	mlx_key_hook(fdf->win, set_hook, fdf);
	mlx_hook(fdf->win, 17, 1L << 0, quit, fdf);
	mlx_expose_hook(fdf->win, expose, fdf);
}
