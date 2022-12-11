/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:24:06 by tquere            #+#    #+#             */
/*   Updated: 2022/12/11 12:25:57 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_point(t_fdf *fdf, int x_pt, int y_pt, int color)
{
	if (x_pt > fdf->res_x || y_pt > fdf->res_y || x_pt < 0 || y_pt < 0)
		return ;
	mlx_pixel_put(fdf->mlx, fdf->win, x_pt, y_pt, color);
}

static void	draw_hori(t_fdf *fdf, t_point_3d *pt_1, t_point_3d *pt_2)
{
	int			x;
	int			y;

	if (pt_1->x < pt_2->x)
	{
		x = pt_1->x;
		while (x < pt_2->x)
		{	
			y = pt_1->y + ((pt_2->y - pt_1->y)
					/ (pt_2->x - pt_1->x)) * (x - pt_1->x);
			draw_point(fdf, x, y, 0xFFFFFF);
			x++;
		}
	}
	else
	{
		x = pt_1->x;
		while (x > pt_2->x)
		{	
			y = pt_1->y + ((pt_2->y - pt_1->y)
					/ (pt_2->x - pt_1->x)) * (x - pt_1->x);
			draw_point(fdf, x, y, 0xFFFFFF);
			x--;
		}
	}
}

static void	draw_verti(t_fdf *fdf, t_point_3d *pt_1, t_point_3d *pt_2)
{
	int			x;
	int			y;

	if (pt_1->y < pt_2->y)
	{
		y = pt_1->y;
		while (y < pt_2->y)
		{
			x = pt_1->x + ((pt_2->x - pt_1->x)
					/ (pt_2->y - pt_1->y)) * (y - pt_1->y);
			draw_point(fdf, x, y, 0xFFFFFF);
			y++;
		}
	}
	else
	{
		y = pt_1->y;
		while (y > pt_2->y)
		{	
			x = pt_1->x + ((pt_2->x - pt_1->x)
					/ (pt_2->y - pt_1->y)) * (y - pt_1->y);
			draw_point(fdf, x, y, 0xFFFFFF);
			y--;
		}
	}
}

void	draw_ligne(t_fdf *fdf, t_point_3d *pt_1, t_point_3d *pt_2)
{
	double		dx;
	double		dy;

	if (!pt_1 || !pt_2)
		return ;
	dx = pt_2->x - pt_1->x;
	dy = pt_2->y - pt_1->y;
	if (dx * dx > dy * dy)
		draw_hori(fdf, pt_1, pt_2);
	else
		draw_verti(fdf, pt_1, pt_2);
}
