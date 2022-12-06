/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:24:06 by tquere            #+#    #+#             */
/*   Updated: 2022/12/06 20:30:44 by tquere           ###   ########.fr       */
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

void	draw_ligne(t_fdf *fdf, t_point_3d *pt_1, t_point_3d *pt_2, int color)
{
	int			x;
	int			y;
	double		coef_dir;
	t_point_3d	*tmp;

	// if (pt_2->x < pt_1->x)
	// {
	// 	tmp = pt_1;
	// 	pt_1 = pt_2;
	// 	pt_2 = pt_1;
	// }

	//Si dif x > dif
	if ((pt_2->x - pt_1->x) > (pt_2->y - pt_1->y))
	{	
		coef_dir = (pt_2->y - pt_1->y) / (pt_2->x - pt_1->x);
		x = pt_1->x;
		while (x < pt_2->x)
		{	
			y = pt_1->y + coef_dir * (x - pt_1->x);
			if (!(x > fdf->res_x || y > fdf->res_y || x < 0 || y < 0))
				draw_point(fdf, x, y, color);
			x++;
		}
	}
	else
	{	
		coef_dir = (pt_2->x - pt_1->x) / (pt_2->y - pt_1->y);
		y = pt_1->y;
		while (y < pt_2->y)
		{
			x = pt_1->x + coef_dir * (y - pt_1->y);
			if (!(x > fdf->res_x || y > fdf->res_y || x < 0 || y < 0))
				draw_point(fdf, x, y, color);
			y++;
		}
	}
}
