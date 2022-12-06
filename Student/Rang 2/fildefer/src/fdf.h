/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:38:26 by tquere            #+#    #+#             */
/*   Updated: 2022/12/06 17:18:32 by tquere           ###   ########.fr       */
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
# define WIN_NAME "FDF TQUERE"

// enum les key clavier

// Point 3D
typedef struct s_point_3d
{
	double		x;
	double		y;
	double		z;
	double		w;

}	t_point_3d;

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
	double		t_x;
	double		t_y;
	double		t_z;
	double		r_x;
	double		r_y;
	double		r_z;
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

	t_point_3d	**mat_3d;
	double		*mat_proj;
	double		*mat_rot;
	double		*mat_trans;
	t_point_3d	**mat_3d_proj;

	double		ratio;
	int			res_x;
	int			res_y;

	int			draw_witdh;

}	t_fdf;

// main
int			update(t_fdf *fdf);

// debug
void		print_map(t_fdf *fdf);
void		print_mat_3d(t_fdf *fdf, t_point_3d **mat);
void		print_mat_proj(t_fdf *fdf);

// malloc
t_fdf		*init_fdf(void);
void		free_exit(t_fdf *fdf, int error_code);
void		malloc_map_value(t_fdf *fdf);

// map_error
void		get_map_size(t_fdf *fdf, int fd);

// args_check
void		check_args(t_fdf *fdf, int argc, char **argv);

// parse map
void		parse_map(t_fdf *fdf);

// matrice points
t_point_3d	**new_matrice_3d(t_fdf *fdf);
t_point_3d	*new_point_3d(t_fdf *fdf, double x, double y, double z);
void		free_matrice_3d(t_fdf *fdf, t_point_3d **mat);
void		init_mat_3d(t_fdf *fdf, t_point_3d **mat);
void		get_value_mat_3d(t_fdf *fdf);

// matrice_proj
void		malloc_matrice_proj(t_fdf *fdf);
void		init_mat_proj(t_fdf *fdf);
void		get_mat_proj(t_fdf *fdf);
void		apply_proj(t_fdf *fdf);
void		scale_to_res(t_fdf *fdf);

// matrice product
double		proj_product_x(t_fdf *fdf, t_point_3d *point_3d);
double		proj_product_y(t_fdf *fdf, t_point_3d *point_3d);
double		proj_product_z(t_fdf *fdf, t_point_3d *point_3d);
double		proj_product_w(t_fdf *fdf, t_point_3d *point_3d);

// matrice translate
void		translate(t_fdf *fdf);

// matrice translate
void		rotate(t_fdf *fdf);

// mlx
void		init_mlx(t_fdf *fdf);
void		start_mlx(t_fdf *fdf);
void		update_img(t_fdf *fdf);

// draw
void		draw_point(t_fdf *fdf, int x_pt, int y_pt);
void		draw_ligne(t_fdf *fdf, t_point_3d *pt_1, t_point_3d *pt_2);

#endif
