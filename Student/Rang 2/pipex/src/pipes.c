/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 07:40:28 by tquere            #+#    #+#             */
/*   Updated: 2022/12/13 17:37:48 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipes(t_env *e, int nb_cmd)
{
	int	i;

	i = 0;
	while (i < nb_cmd * 2 + 2)
		close(e->pipes[i++]);
}

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
}
