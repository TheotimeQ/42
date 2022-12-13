/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 07:17:10 by tquere            #+#    #+#             */
/*   Updated: 2022/12/13 15:27:54 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(t_env *e, int argc, char **argv)
{

	//Gestion du < ou <<  ( create , append , reset )

	if (argc < 5)
	{
		ft_printf(2, "Wrong use : ./pipex file1 cmd1 cmd2 file2\n");
		free_exit(e, 1);
	}
	e->fd_input = open(argv[1], O_RDONLY);
	if (e->fd_input < 0)
	{
		ft_printf(2, "Error: %s \n", strerror(errno));
		free_exit(e, 1);
	}
	e->fd_output = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (e->fd_output < 0)
	{
		ft_printf(2, "Error: %s \n", strerror(errno));
		free_exit(e, 1);
	}
}
