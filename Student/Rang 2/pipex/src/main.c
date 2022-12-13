/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:36:54 by tquere            #+#    #+#             */
/*   Updated: 2022/12/13 17:02:14 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_exit(t_env *e, int error_code)
{	
	free_split(e->path);
	free(e->pipes);
	if (e->fd_input > 0)
		close(e->fd_input);
	if (e->fd_input > 0)
		close(e->fd_output);
	free(e);
	exit(error_code);
}

static t_env	*init_env(void)
{
	t_env	*e;

	e = malloc(sizeof(e));
	if (e == NULL)
	{
		ft_printf(2, "Error: malloc env\n");
		exit(1);
	}
	e->pipes = NULL;
	return (e);
}

static void	get_path(t_env *e, char *envp[])
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	e->path = ft_split(*envp + 5, ':');
	if (e->path == NULL)
		free_exit(e, 1);
}

//     READ                             FIRST                           SECOND                       WRITE IN FILE     													
//stdin | pipe0_ecriture - pipe0_lecture  | pipe1_ecriture - pipe1_lecture | pipe2_ecriture  pipe2_lecture | output |

int	main(int argc, char **argv, char *envp[])
{	
	t_env	*e;
	int		status;

	e = init_env();
	
	check_args(e, argc, argv);
	get_path(e, envp);

	// printf("\n\npath : %s %s %s\n", e->path[0], e->path[1], e->path[2]);
	
	ft_printf(1, "\nnb_pipe : %d , fd_in : %d, fd_out : %d\n\n", argc - 4, e->fd_input, e->fd_output);
	create_pipes(e, argc - 4);
	fork_cmd(e, argc - 3, argv, envp);

	close_pipes(e, argc - 4);
	close(STDOUT_FILENO);
	close(STDIN_FILENO);

	// fd_to_fd(e, argc - 2, e->fd_input, STDIN_FILENO);
	// fd_to_fd(e, argc - 2, e->pipes[(argc - 3) * 2 + 1], 2); //e->pipes[(argc - 3) * 2 + 1], e->fd_output);
	
	int i;

	i = 0;
	while(i < argc - 4)
	{
		waitpid(-1, &status, 0);
		i++;
	}	
	
	exit(0);
}























//  1    2     3     4     5
// NAME INPUT CMD1 CMD2 OUTPUT


// t_env *init_env(void)
// {
// 	t_env	*e;

// 	e = malloc(sizeof(e));
// 	if (fdf == NULL)
// 	{
// 		ft_printf(2, "Error: malloc env\n");
// 		free_exit(e, 1);
// 	}
// 	return (e);
// }

// open, close, read, write,
// malloc, free, perror,
// strerror, access, dup, dup2,
// execve, exit, fork, pipe,
// unlink, wait, waitpid

// ./pipex file1 cmd1 cmd2 file2
// •file1 et file2 sont des noms de fichier.
// •cmd1 et cmd2 sont des commandes shell avec leurs paramètres.

// Similaire à : < file1 cmd1 | cmd2 > file2

// ./pipex infile "ls -l" "wc -l" outfile
// < infile ls -l | wc -l > outfile

//  ./pipex infile "grep a1" "wc -w" outfile
//  < infile grep a1 | wc -w > outfile