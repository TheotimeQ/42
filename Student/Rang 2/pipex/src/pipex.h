/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:38:26 by tquere            #+#    #+#             */
/*   Updated: 2022/12/13 14:42:36 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>

# include <stdio.h>

# include "../libft/libft.h"

typedef struct s_env
{	
	char	**path;

	int		fd_input;
	int		fd_output;

	int		*pipes;

}	t_env;

void	free_exit(t_env *e, int error_code);

void	check_args(t_env *e, int argc, char **argv);

void	custom_dup(int input, int output);
void	fork_cmd(t_env *e, int argc, char **argv, char *envp[]);

void	close_pipes(t_env *e, int nb_cmd);
void	create_pipes(t_env *e, int nb_cmd);

void	fd_to_fd(t_env *e, int nb_cmd, int fd_input, int fd_output);

#endif
