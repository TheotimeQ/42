/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_write_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 07:21:02 by tquere            #+#    #+#             */
/*   Updated: 2022/12/13 14:43:04 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fd_to_fd(t_env *e, int nb_cmd, int fd_input, int fd_output)
{
	char	*str;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{	
		ft_printf(2, "Reading from : %d -> writing in %d\n",fd_input,fd_output);
		
		str = get_next_line(fd_input);
		if (str)
			write(fd_output, str, ft_strlen(str));
		while (str)
		{	
			free(str);
			str = get_next_line(fd_input);
			if (str)
				write(fd_output, str, ft_strlen(str));
		}
		free(str);
		exit(0);
	}
}








