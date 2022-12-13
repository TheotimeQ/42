/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 07:20:52 by tquere            #+#    #+#             */
/*   Updated: 2022/12/13 17:06:21 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_cmd(char **paths, char *cmd)
{
	char	*command;

	while (*paths)
	{
		command = ft_strjoin(*paths, "/");
		command = ft_strjoin(command, cmd);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	close_pipes(t_env *e, int nb_cmd)
{
	int	i;

	i = 0;
	while (i < nb_cmd * 2 + 2)
	{
		// ft_printf(2, "Closing : %d    %d\n",i,nb_cmd);
		close(e->pipes[i++]);
	}
}

void	fork_cmd(t_env *e, int nb_cmd, char **argv, char *envp[])
{
	pid_t	pid;
	int		id_cmd;
	char	**cmd_args;
	char	*cmd_path;

	int 	fd_input;
	int 	fd_output;

	id_cmd = 0;
	while (id_cmd < nb_cmd)
	{
		
		pid = fork();
		if (pid < 0)
		{
			perror("Error fork");
			free_exit(e, 1);
		}
		if (pid == 0)
		{

			fd_input = e->pipes[id_cmd * 2];
			fd_output = e->pipes[id_cmd * 2 + 1];
			
			ft_printf(2, "Executing : %s , pipe_in :%d, pipe_out :%d\n", argv[id_cmd + 2], fd_input, fd_output);
			
			//STDIN = lecture du pipe d'avant
			dup2(fd_input, STDIN_FILENO);

			//STDOUT = ecriture du pipe d'apres
			dup2(fd_output, STDOUT_FILENO);
			
			close_pipes(e, nb_cmd - 1);
			// close(STDOUT_FILENO);
			// close(STDIN_FILENO);
			
			cmd_args = ft_split(argv[id_cmd + 2], ' ');
			cmd_path = get_cmd(e->path, cmd_args[0]);
			execve(cmd_path, cmd_args, envp);
			ft_printf(2, "Error : Command %s not found\n", argv[id_cmd + 2]);
			free_split(cmd_args);
			exit(0);
			// ft_printf(1, "Command found in :%s\n",cmd_path);
		}
		id_cmd++;
	}
}
