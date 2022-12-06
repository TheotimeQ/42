/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:24:06 by tquere            #+#    #+#             */
/*   Updated: 2022/12/06 17:17:58 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_point(t_fdf *fdf, int x_pt, int y_pt)
{
	int		x;
	int		y;

	y = y_pt - fdf->draw_witdh;
	while (y < y_pt)
	{
		x = x_pt - fdf->draw_witdh;
		while (x < x_pt)
		{
			mlx_pixel_put(fdf->mlx, fdf->win, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

// void	draw_ligne(t_fdf *fdf, t_point_3d *pt_1, t_point_3d *pt_2)
// {
// 	int		x;
// 	int		y;

// 	// y = y_pt - fdf->draw_witdh;
// 	// while (y < y_pt)
// 	// {
// 	// 	x = x_pt - fdf->draw_witdh;
// 	// 	while (x < x_pt)
// 	// 	{
// 	// 		mlx_pixel_put(fdf->mlx, fdf->win, x, y, 0xFFFFFF);
// 	// 		x++;
// 	// 	}
// 	// 	y++;
// 	// }
// }
