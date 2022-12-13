/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 07:40:28 by tquere            #+#    #+#             */
/*   Updated: 2022/12/13 16:41:41 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_pipes(t_env *e, int nb_pipe)
{	
	int	id_pipe;
	int	fd_pipe;
	int	tmp;

	e->pipes = malloc(sizeof(int) * nb_pipe * 2 + 2);
	if (e->pipes == NULL)
	{
		ft_printf(2, "Error: malloc env\n");
		free_exit(e, 1);
	}
	id_pipe = 0;
	e->pipes[0] = e->fd_input;
	while (id_pipe < nb_pipe)
	{	
		fd_pipe = pipe(e->pipes + id_pipe * 2 + 1);
		if (fd_pipe == 1)
			free_exit(e, 1);
		tmp = e->pipes[id_pipe * 2 + 1];
		e->pipes[id_pipe * 2 + 1] = e->pipes[id_pipe * 2 + 2];
		e->pipes[id_pipe * 2 + 2] = tmp;
		id_pipe++;
	}
	e->pipes[nb_pipe * 2 + 1] = e->fd_output;

	id_pipe = 0;
	ft_printf(1,"| %d ", e->pipes[0]);
	while (id_pipe < nb_pipe)
	{
		ft_printf(1,"| %d , %d ", e->pipes[id_pipe * 2 + 1], e->pipes[id_pipe * 2 + 2]);
		id_pipe++;
	}
	ft_printf(1,"| %d |", e->pipes[nb_pipe * 2 + 1]);
	ft_printf(1,"\n\n");
}
