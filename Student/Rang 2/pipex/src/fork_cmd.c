/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 07:20:52 by tquere            #+#    #+#             */
/*   Updated: 2023/01/05 15:59:50 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

static char	*get_cmd_path(char **paths, char *cmd)
{
	char	*command;

	while (*paths)
	{
		command = ft_strjoin(*paths, "/");
		command = ft_strjoin(command, cmd);
		if (!access(command, 0))
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

static void	one_child(t_env *e, int id_cmd, char **argv, char *envp[])
{
	int		fd_input;
	int		fd_output;
	char	**cmd_args;
	char	*cmd_path;

	fd_input = e->pipes[id_cmd * 2];
	fd_output = e->pipes[id_cmd * 2 + 1];
	dup2(fd_input, STDIN_FILENO);
	dup2(fd_output, STDOUT_FILENO);
	close_pipes(e, e->nb_cmd - 1);
	cmd_args = ft_split(argv[id_cmd + 2], ' ');
	cmd_path = get_cmd_path(e->path, cmd_args[0]);
	printf("args : %s \n",cmd_args);
	printf("path : %s \n",cmd_path);
	execve(cmd_path, cmd_args, envp);
	ft_printf(2, "Error: command not found: %s\n", argv[id_cmd + 2]);
	free_split(cmd_args);
	exit(0);
}

void	fork_cmd(t_env *e, int nb_cmd, char **argv, char *envp[])
{
	pid_t	pid;
	int		id_cmd;

	id_cmd = 0;
	e->nb_cmd = nb_cmd;
	while (id_cmd < nb_cmd)
	{
		pid = fork();
		if (pid < 0)
		{
			ft_printf(2, "Error: fork\n");
			free_exit(e, 1);
		}
		if (pid == 0)
			one_child(e, id_cmd, argv, envp);
		id_cmd++;
	}
}
