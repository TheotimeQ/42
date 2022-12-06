/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:36:54 by tquere            #+#    #+#             */
/*   Updated: 2022/12/06 17:07:57 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	update_mat_3D_proj(t_fdf *fdf)
{	
	ft_printf(2, "\n\n--------------------------------------\n");
	ft_printf(2, "x:%d y:%d min_z:%d max_z:%d\n\n",fdf->map->max_x, fdf->map->max_y, fdf->map->min_z, fdf->map->max_z);
	printf("t_x:%.2f t_y:%.2f t_z:%.2f fov:%.2f\n\n", fdf->cam->t_x, fdf->cam->t_y, fdf->cam->t_z, fdf->cam->fov);
	printf("r_x:%.2f r_y:%.2f r_z:%.2f \n\n", fdf->cam->r_x, fdf->cam->r_y, fdf->cam->r_z);

	//update 3D matrice
	get_mat_proj(fdf);
	apply_proj(fdf);

	ft_printf(2, "MAT 3D\n");
	print_mat_3d(fdf, fdf->mat_3d);
	ft_printf(2, "MAT 3D PROJ\n");
	print_mat_3d(fdf, fdf->mat_3d_proj);
	ft_printf(2, "MAT PROJ\n");
	print_mat_proj(fdf);

	scale_to_res(fdf);
	ft_printf(2, "MAT 3D PROJ SCALED\n");
	print_mat_3d(fdf, fdf->mat_3d_proj);
}

int	main(int argc, char **argv)
{	
	t_fdf	*fdf;

	//Setup Env
	fdf = init_fdf();

	//Map parsing
	check_args(fdf, argc, argv);
	parse_map(fdf);
	print_map(fdf);

	//init mlx
	init_mlx(fdf);

	//Init mat 3D
	fdf->mat_3d = new_matrice_3d(fdf);
	init_mat_3d(fdf, fdf->mat_3d);
	get_value_mat_3d(fdf);

	// init mat proj
	malloc_matrice_proj(fdf);
	init_mat_proj(fdf);

	// //init mat tran
	// malloc_matrice_tran(fdf);
	// init_mat_tran(fdf);

	// //init mat rot
	// malloc_matrice_rot(fdf);
	// init_mat_rot(fdf);

	//init mat 3D proj
	fdf->mat_3d_proj = new_matrice_3d(fdf);
	init_mat_3d(fdf, fdf->mat_3d_proj);

	//Creer l'image à afficher
	update_mat_3D_proj(fdf);
	update_img(fdf);

	//demare a loop mlx
	mlx_loop(fdf->mlx);

	free_exit(fdf, 0);
}
