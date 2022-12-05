#include "fdf.h"

static void		key_rotation(int keycode, t_fdf *fdf)
{
	if (keycode == 17)
		fdf->cam->rx += 1;
	if (keycode == 16)
		fdf->cam->rx -= 1;
	if (keycode == 5)
		fdf->cam->ry += 1;
	if (keycode == 4)
		fdf->cam->ry -= 1;
	if (keycode == 45)
		fdf->cam->rz += 1;
	if (keycode == 11)
		fdf->cam->rz -= 1;
}

static void		key_move(int keycode, t_fdf *fdf)
{
	if (keycode == 65361)
		fdf->cam->x += 1;
	if (keycode == 65363)
		fdf->cam->x -= 1;
	if (keycode == 65362)
		fdf->cam->y += 1;
	if (keycode == 65364)
		fdf->cam->y -= 1;
	if (keycode == 3)
		fdf->cam->z += 1;
	if (keycode == 15)
		fdf->cam->z -= 1;
}

static void		key_zoom(int keycode, t_fdf *fdf)
{
	if (keycode == 65453)
		fdf->cam->fov -= 0.025;
	if (keycode == 65451)
		fdf->cam->fov += 0.025;
	if (fdf->cam->fov > 3.14)
		fdf->cam->fov = 3.14;
	if (fdf->cam->fov < 0)
		fdf->cam->fov = 0;
}

static int	set_hook(int keycode, t_fdf *fdf)
{   
    ft_printf(1, "Key down: %d \n",keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		free_exit(fdf,0);
	}
	key_rotation(keycode, fdf);
	key_move(keycode, fdf);
    key_zoom(keycode, fdf);
    update(fdf);
	return (0);
}

void    init_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, RES_X, RES_Y, WIN_NAME);
    mlx_key_hook(fdf->win, set_hook, fdf);
}

void    start_mlx(t_fdf *fdf)
{
	mlx_loop(fdf->mlx);
}




//Mettre les bons code de touche pour linux / mac