/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:52:24 by tquere            #+#    #+#             */
/*   Updated: 2022/12/11 12:32:53 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_args(t_fdf *fdf, int argc, char **argv)
{	
	int	fd;

	if (argc != 2)
	{
		ft_printf(2, "Wrong use : ./fdf [filename.fdf]\n");
		free_exit(fdf, 1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf(2, "Error: %s \n", strerror(errno));
		free_exit(fdf, 1);
	}
	fdf->map->map_name = argv[1];
	get_map_size(fdf, fd);
	close(fd);
}
