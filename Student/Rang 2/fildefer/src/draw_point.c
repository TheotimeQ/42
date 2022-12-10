/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:24:06 by tquere            #+#    #+#             */
/*   Updated: 2022/12/10 11:06:40 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_point(t_fdf *fdf, int x_pt, int y_pt, int color)
{
	int		x;
	int		y;

	y = y_pt - fdf->draw_witdh;
	while (y < y_pt)
	{
		x = x_pt - fdf->draw_witdh;
		while (x < x_pt)
		{	
			if (!(x > fdf->res_x || y > fdf->res_y || x < 0 || y < 0))
				mlx_pixel_put(fdf->mlx, fdf->win, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_ligne(t_fdf *fdf, t_point_3d *pt_1, t_point_3d *pt_2)
{
	int			x;
	int			y;
	double 		dx;
	double 		dy;
	int			sign;
	int			color = 0xFFFFFF;


	dx = pt_2->x - pt_1->x;
	dy = pt_2->y - pt_1->y;
	if (dx * dx > dy * dy)
	{	
		if (pt_1->x < pt_2->x)
		{
			x = pt_1->x;
			while (x < pt_2->x)
			{	
				y = pt_1->y + (dy / dx) * (x - pt_1->x);
				if (!(x > fdf->res_x || y > fdf->res_y || x < 0 || y < 0))
					draw_point(fdf, x, y, color);
				x++;
			}
		}
		else
		{
			x = pt_1->x;
			while (x > pt_2->x)
			{	
				y = pt_1->y + (dy / dx) * (x - pt_1->x);
				if (!(x > fdf->res_x || y > fdf->res_y || x < 0 || y < 0))
					draw_point(fdf, x, y, color);
				x--;
			}
		}
	}
	//Vertical
	else
	{	
		if (pt_1->y < pt_2->y)
		{
			y = pt_1->y;
			while (y < pt_2->y)
			{
				x = pt_1->x + (dx / dy) * (y - pt_1->y);
				if (!(x > fdf->res_x || y > fdf->res_y || x < 0 || y < 0))
					draw_point(fdf, x, y, color);
				y++;
			}
		}
		else
		{
			y = pt_1->y;
			while (y > pt_2->y)
			{	
				x = pt_1->x + (dx / dy) * (y - pt_1->y);
				if (!(x > fdf->res_x || y > fdf->res_y || x < 0 || y < 0))
					draw_point(fdf, x, y, color);
				y--;
			}
		}
	}
}