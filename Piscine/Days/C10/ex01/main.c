/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 22:44:28 by tquere            #+#    #+#             */
/*   Updated: 2022/07/28 10:38:39 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>

void	ft_putstr(char *str, int output)
{
	int	index;

	index = 0;
	while (str[index])
	{
		write(output, &str[index], 1);
		index++;
	}
}

void	read_file(int file)
{	
	char		buffer[30];
	int			bytes;

	bytes = 1 ;
	while (bytes)
	{	
		bytes = read(file, buffer, 20);
		buffer[bytes] = 0;
		write (1, buffer, bytes);
	}
	return ;
}

void	loop_file(int argc, char **argv)
{	
	int		index;
	char	*base;
	char	*file_name;
	int		file;

	index = 1;
	while (index < argc)
	{
		file_name = argv[index++];
		base = basename(file_name);
		file = open(file_name, O_RDWR);
		if (file == -1)
		{
			ft_putstr("cat: ", 2);
			ft_putstr(file_name, 2);
			ft_putstr(": ", 2);
			ft_putstr(strerror(errno), 2);
			ft_putstr("\n", 2);
		}
		else
		{
			read_file(file);
			close(file);
		}
	}
}

void	open_stdin(void)
{	
	int			file;
	char		buffer[30];

	file = open(STDIN_FILENO, O_RDWR);
	while (read(STDIN_FILENO, buffer, 1) > 0)
	{
		write(1, buffer, 1);
	}
	close(file);
}

int	main(int argc, char **argv)
{	
	if (argc == 1)
	{
		open_stdin();
		return (1);
	}
	else
		loop_file(argc, argv);
	return (0);
}
