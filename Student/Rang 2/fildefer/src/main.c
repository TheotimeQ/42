/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:36:54 by tquere            #+#    #+#             */
/*   Updated: 2022/12/07 21:50:10 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update(t_fdf *fdf)
{	
	ft_printf(2, "\n\n--------------------------------------\n");
	ft_printf(2, "x:%d y:%d min_z:%d max_z:%d\n\n",fdf->map->max_x, fdf->map->max_y, fdf->map->min_z, fdf->map->max_z);
	printf("t_x:%.2f t_y:%.2f t_z:%.2f fov:%.2f\n\n", fdf->cam->t_x, fdf->cam->t_y, fdf->cam->t_z, fdf->cam->fov);
	printf("r_x:%.2f r_y:%.2f r_z:%.2f \n\n", fdf->cam->r_x, fdf->cam->r_y, fdf->cam->r_z);
	printf("x_pos:%.2f y_pos:%.2f z_pos:%.2f \n\n", fdf->x_pos, fdf->y_pos, fdf->z_pos);
	printf("x_rot:%.2f y_rot:%.2f z_rot:%.2f \n\n", fdf->x_rot, fdf->y_rot, fdf->z_rot);
	
	int			x;
	int			y;

	get_mat_proj(fdf);
	get_rotate_vector(fdf);
	get_mat_rot(fdf);


	y = 0;
	while (y < fdf->mat_3d_proj->size_y)
	{
		x = 0;
		while (x < fdf->mat_3d_proj->size_x)
		{	
			rotate(fdf, x, y);
			translate(fdf, x, y);
			project(fdf, x, y);
			scale(fdf, x, y);
			x++;
		}
		y++;
	}
	
	//APPLIQUER LES MEME ROTATION SUR LES VECTEUR POUR TOURNER PAR RAPPORT A L OBJET
	rotate_vector(fdf,fdf->u_x);
	rotate_vector(fdf,fdf->u_y);
	rotate_vector(fdf,fdf->u_z);

	fdf->cam->t_x = 0;
	fdf->cam->t_y = 0;
	fdf->cam->t_z = 0;
	fdf->cam->r_x = 0;
	fdf->cam->r_y = 0;
	fdf->cam->r_z = 0;

	ft_printf(1, "VECTOR \n");
	print_u_vector(fdf);
	// ft_printf(1, "MAT 3D \n");
	// print_matrice(fdf->mat_3d);
	// ft_printf(1, "MAT 3D PROJ\n");
	// print_matrice(fdf->mat_3d_proj);
	// ft_printf(1, "MAT PROJ\n");
	// print_matrice(fdf->mat_proj);
	// ft_printf(1, "MAT ROT\n");
	// print_matrice(fdf->mat_rot);

	update_img(fdf);
}

int	main(int argc, char **argv)
{	
	t_fdf	*fdf;

	//Setup Env
	fdf = init_fdf();

	//Map parsing
	check_args(fdf, argc, argv);
	parse_map(fdf);
	
	ft_printf(1, "MAP \n");
	print_map(fdf);

	//init mlx
	init_mlx(fdf);

	//Create all matrice
	fdf->mat_3d = new_matrice(fdf, fdf->map->max_x, fdf->map->max_y);
	fdf->mat_3d_proj = new_matrice(fdf, fdf->map->max_x, fdf->map->max_y);
	fdf->mat_proj = new_matrice(fdf, 4, 4);
	fdf->mat_rot = new_matrice(fdf, 3, 3);

	//Init mat 3D
	get_mat_3D(fdf);

	fdf->cam->t_x = - fdf->map->max_x / 2 + 1;
	fdf->cam->t_y = - fdf->map->max_y / 2 + 1;
	if (fdf->map->max_y > fdf->map->max_x)
		fdf->cam->t_z = fdf->map->max_y * 10 + 2;
	else	
		fdf->cam->t_z = fdf->map->max_x * 10 + 2;
	fdf->cam->fov = 0.15;
	
	//Update
	update(fdf);

	//demare a loop mlx
	mlx_loop(fdf->mlx);

	free_exit(fdf, 0);
}
