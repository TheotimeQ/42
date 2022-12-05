

#include "fdf.h"

void	check_args(t_fdf *fdf, int argc, char **argv)
{	
	int	fd;
	
	if (argc != 2)
	{
		ft_printf(2, "Wrong use : ./fdf [filename.fdf]\n");
		free_exit(fdf,1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf(2, "Error: %s \n",strerror(errno));
		free_exit(fdf,1);
	}
	fdf->map->map_name = argv[1];
	get_map_size(fdf, fd);
    close(fd);
}