/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:38:26 by tquere            #+#    #+#             */
/*   Updated: 2022/12/05 19:58:28 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <math.h>
// https://koor.fr/C/cmath/cmath.wp

# include <stdio.h>

# include "../libft/libft.h"
// # include "../minilibx_macos/mlx.h"
# include "../minilibx_linux/mlx.h"

#define RES_X 1000
#define RES_Y 1000
#define WIN_NAME "FDF TQUERE"

// enum les key clavier

//Point 3D
typedef struct s_point_3D
{
	double	x;
	double	y;
	double	z;
	double	w;

}	t_point_3D;

//Map
typedef struct s_map
{
	int		*values;
	int		max_x;
	int		max_y;
	int		min_z;
	int		max_z;
	char	*map_name;

}	t_map;

//Cam object
typedef struct s_cam
{
	double	x;
	double	y;
	double	z;
	double	rx;
	double	ry;
	double  rz;
	double  fov;
	double	z_min;
	double	z_max;
	
}	t_cam;

//Stock tous les objets
typedef struct s_fdf
{
	t_map			*map;
	t_cam			*cam;

	void			*mlx;
	void			*win;
	void			*img;
	
	t_point_3D		**mat_3D;
	double			*mat_proj;

	double			ratio;
	int				res_x;
	int				res_y;
	
}	t_fdf;

//main
int			update(t_fdf *fdf);

//debug
void    	print_map(t_fdf *fdf);
void    	print_mat_3D(t_fdf *fdf);
void		print_mat_proj(t_fdf *fdf);

//malloc
t_fdf		*init_fdf(void);
void		free_exit(t_fdf *fdf, int error_code);
void		malloc_map_value(t_fdf *fdf);

//map_error
void		get_map_size(t_fdf *fdf,int fd);

//args_check
void		check_args(t_fdf *fdf, int argc, char **argv);

//parse map
void    	parse_map(t_fdf *fdf);

//matrice points 
void    	malloc_matrice_3D(t_fdf *fdf);
void    	free_matrice_3D(t_fdf *fdf);
void 		init_mat_3D(t_fdf *fdf);
void 		update_mat_3D(t_fdf *fdf);

//matrice_proj
void    	malloc_matrice_proj(t_fdf *fdf);
void 		init_mat_proj(t_fdf *fdf);
void 		get_mat_proj(t_fdf *fdf);
void    	apply_proj(t_fdf *fdf);
void    	scale_to_res(t_fdf *fdf);

//mlx
void    	init_mlx(t_fdf *fdf);
void    	start_mlx(t_fdf *fdf);
void    	update_img(t_fdf *fdf);

#endif


//map pas carré?
//Limit valeur dans la map ? 





// https://www.youtube.com/watch?v=SGLK2p3PIqE















// https://github.com/loudur/fdf/blob/master/Makefile

// strerror
// perror

// outes les fonctions de la
// bibliothèque mathématique
// (option de compilation -lm,
// man man 3 math

// Votre programme doit afficher une image dans une fenêtre.
// •La gestion de la fenêtre doit rester fluide (changer de fenêtre, la réduire, etc.).
// •Appuyer sur la touche ESC doit fermer la fenêtre et quitter le programme propre-
// ment.
// •Cliquer sur la croix en haut de la fenêtre doit fermer celle-ci et quitter le programme
// proprement.
// •Utiliser les images de la MiniLibX est obligatoire

//rotation translation zoom ?

// tar -xvf filename.tar.gz