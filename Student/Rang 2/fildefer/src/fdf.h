/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:38:26 by tquere            #+#    #+#             */
/*   Updated: 2023/01/08 11:07:27 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

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

# define RES_X 2000
# define RES_Y 1500
# define INC_TRANS 0.2
# define INC_ROT 0.1
# define INC_FOV 0.02
# define WIN_NAME "FDF TQUERE"

typedef struct s_point_3d
{
	double		x;
	double		y;
	double		z;
	double		w;

}	t_point_3d;

typedef struct s_matrice
{
	t_point_3d	**array;
	int			size_x;
	int			size_y;

}	t_matrice;

typedef struct s_map
{
	int				max_x;
	int				max_y;
	int				min_z;
	int				max_z;
	char			*map_name;

}	t_map;

typedef struct s_cam
{
	double		fov;
	double		z_min;
	double		z_max;

}	t_cam;

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

	double		max_coord;

	double		inc_z;
	double		inc_fov;
	double		inc_trans;

	int			max_color;
	int			min_color;

}	t_fdf;

void		print_infos(t_fdf *fdf);

void		update(t_fdf *fdf);
void		reset(t_fdf *fdf);

t_fdf		*init_fdf(void);
void		free_exit(t_fdf *fdf, int error_code);

void		get_map_size(t_fdf *fdf, int fd);
void		check_args(t_fdf *fdf, int argc, char **argv);
void		parse_map(t_fdf *fdf);

t_point_3d	*new_point_3d(t_fdf *fdf, double x, double y, double z);

t_matrice	*new_matrice(t_fdf *fdf, int size_x, int size_y);
void		free_matrice(t_matrice *matrice);
void		get_mat_3D(t_fdf *fdf);
void		get_mat_proj(t_fdf *fdf);
void		cpy_point_3d(t_fdf *fdf, int x, int y);
void		project(t_fdf *fdf, int x, int y);
void		center_map(t_fdf *fdf, int x, int y);
void		translate(t_fdf *fdf, int x, int y);

t_point_3d	*rot_point(t_fdf *fdf,
				t_point_3d *point_3d, t_matrice *matrice_rot);
void		get_rotate_vector(t_fdf *fdf);
void		get_mat_rot(t_fdf *fdf);
void		rotate(t_fdf *fdf, int x, int y);

void		scale(t_fdf *fdf, int x, int y);

void		init_mlx(t_fdf *fdf);
void		start_mlx(t_fdf *fdf);
void		update_img(t_fdf *fdf);
void		key_zoom(int keycode, t_fdf *fdf);
void		key_move(int keycode, t_fdf *fdf);

void		draw_ligne(t_fdf *fdf, t_point_3d *pt_1, t_point_3d *pt_2);

#endif
