/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:38:26 by tquere            #+#    #+#             */
/*   Updated: 2022/12/07 23:53:30 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//REMOVE
# include <stdio.h>

# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <math.h>

# include "../libft/libft.h"
# include "fdf_keys.h"

# ifdef __gnu_linux__
#  include "../minilibx_linux/mlx.h"
# else
#  include "../minilibx_macos/mlx.h"
# endif

# define RES_X 1000
# define RES_Y 1000
# define DRAW_WITDH 2
# define INC_TRANS 0.8
# define INC_ROT 0.2
# define WIN_NAME "FDF TQUERE"

// Point 3D
typedef struct s_point_3d
{
	double		x;
	double		y;
	double		z;
	double		w;

}	t_point_3d;

// Matrice 
typedef struct s_matrice
{
	t_point_3d	**array;
	int			size_x;
	int			size_y;

}	t_matrice;

// Map
typedef struct s_map
{
	int		*values;
	int		max_x;
	int		max_y;
	int		min_z;
	int		max_z;
	char	*map_name;

}	t_map;

// Cam object
typedef struct s_cam
{
	double		fov;
	double		z_min;
	double		z_max;

}	t_cam;

// Stock tous les objets
typedef struct s_fdf
{
	t_map		*map;
	t_cam		*cam;

	void		*mlx;
	void		*win;
	void		*img;

	t_matrice	*mat_3d;
	t_matrice	*mat_3d_proj;
	t_matrice	*mat_proj;
	t_matrice	*mat_rot;

	double		ratio;
	int			res_x;
	int			res_y;

	int			draw_witdh;
	
	double		t_x;
	double		t_y;
	double		t_z;
	double		r_x;
	double		r_y;
	double		r_z;

}	t_fdf;

// main
void		update(t_fdf *fdf);

// debug
void		print_map(t_fdf *fdf);
void		print_matrice(t_matrice *matrice);
void		print_u_vector(t_fdf *fdf);

// malloc
t_fdf		*init_fdf(void);
void		free_exit(t_fdf *fdf, int error_code);

// map_error
void		get_map_size(t_fdf *fdf, int fd);

// args_check
void		check_args(t_fdf *fdf, int argc, char **argv);

// parse map
void		parse_map(t_fdf *fdf);

// point 3D
t_point_3d	*new_point_3d(t_fdf *fdf, double x, double y, double z);

// matrice
t_matrice	*new_matrice(t_fdf *fdf, int size_x, int size_y);
void		free_matrice(t_matrice *matrice);

// matrice 3D
void		get_mat_3D(t_fdf *fdf);

// matrice_proj
void		get_mat_proj(t_fdf *fdf);
void    	cpy_point_3d(t_fdf *fdf, int x, int y);
void		project(t_fdf *fdf, int x, int y);

// matrice translate
void		center_map(t_fdf *fdf, int x, int y);
void		translate(t_fdf *fdf, int x, int y);

// matrice rotation
t_point_3d	*rot_point(t_fdf *fdf, t_point_3d *point_3d, t_matrice *matrice_rot);
void    	get_rotate_vector(t_fdf *fdf);
void		get_mat_rot(t_fdf *fdf);
void		rotate(t_fdf *fdf, int x, int y);

// matrice scale
void		scale(t_fdf *fdf, int x, int y);

// mlx
void		init_mlx(t_fdf *fdf);
void		start_mlx(t_fdf *fdf);
void		update_img(t_fdf *fdf);

// draw
void		draw_point(t_fdf *fdf, int x_pt, int y_pt, int color);
void		draw_ligne(t_fdf *fdf, t_point_3d *pt_1, t_point_3d *pt_2, int color);

#endif
