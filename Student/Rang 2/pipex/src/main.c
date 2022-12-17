/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:36:54 by tquere            #+#    #+#             */
/*   Updated: 2022/12/15 09:36:36 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(t_env *e, int argc, char **argv)
{
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
	e->path = NULL;
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

int	main(int argc, char **argv, char *envp[])
{	
	t_env		*e;
	int			status;
	int			i;

	e = init_env();
	check_args(e, argc, argv);
	get_path(e, envp);
	create_pipes(e, argc - 4);
	fork_cmd(e, argc - 3, argv, envp);
	close_pipes(e, argc - 4);
	close(STDOUT_FILENO);
	close(STDIN_FILENO);
	i = 0;
	while (i < argc - 4)
	{
		waitpid(-1, &status, 0);
		i++;
	}	
	free_exit(e, 1);
}
