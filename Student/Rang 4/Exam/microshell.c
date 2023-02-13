# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <stdlib.h>

void	ft_puterrnl(char *msg)
{
	while (*msg)
		write(2, msg++, 1);
	write (2, "\n", 1);
}

void	ft_puterr(char *msg)
{
	while (*msg)
		write(2, msg++, 1);
}

void	ft_fatal(void)
{
	ft_puterrnl("error: fatal");
	exit(1);
}

int	exec_cd(char **av, int i)
{
	char	*pathname;

	pathname = av[1];
	if (i != 2)
	{
		ft_puterrnl("error: cd: bad arguments");
		return (1);
	}
	else if (chdir(pathname) == -1)
	{
		ft_puterr("error: cd: cannot change directory to ");
		ft_puterrnl(pathname);
		return (1);
	}
	return (0);
}

int	exec_cmd(char **av, char **envp, int i)
{
	int	status;
	int	fds[2];
	int	ispipe;
	int	pid;

	if (av[i] && strcmp(av[i], "|") == 0)
	{	
		ispipe = 1;
		if (pipe(fds) == -1)
		{
			ft_fatal();
			return (1);
		}
	}
	else
		ispipe = 0;
	pid = fork();
	if (pid == 0)
	{
		av[i] = NULL;
		if (ispipe)
		{
			if (dup2(fds[1], STDOUT_FILENO) == -1 || close(fds[0]) == -1 || close(fds[1]) == -1)
				return (ft_fatal(), 1);
		}
		execve(av[0], av, envp);
		return (ft_puterr("error: cannot execute "), ft_puterrnl(av[0]), 1);
	}
	waitpid(pid, &status, 0);
	if (ispipe)
	{
		if (dup2(fds[0], STDIN_FILENO) == -1 || close(fds[0]) == -1 || close(fds[1]) == -1)
			return (ft_fatal(), 1);
	}
	return (WIFEXITED(status) && WEXITSTATUS(status));
}


int	main(int ac, char *av[], char *envp[])
{
	(void)ac;
	int	status;
	int	i;

	status = 0;
	i = 0;

	while (*av && *(av + 1))
	{
		av++;
		i = 0;
		while (av[i] && strcmp(av[i], "|") != 0 && strcmp(av[i], ";") != 0) 
			i++; 
		if (strcmp(*av, "cd") == 0)
			status = exec_cd(av, i);
		else if (i != 0)
			status = exec_cmd(av, envp, i);
		av += i;
	}
	return (status);
}
