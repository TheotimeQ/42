/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:24:18 by tquere            #+#    #+#             */
/*   Updated: 2022/07/28 10:16:27 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

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
	ssize_t		bytes;

	bytes = 1;
	while (bytes)
	{	
		bytes = read(file, buffer, 10);
		buffer[bytes] = 0;
		write (1, buffer, bytes);
	}
	return ;
}

int	main(int argc, char **argv)
{	
	char	*file_name;
	int		file;

	if (argc > 2)
	{
		ft_putstr("Too many arguments.\n", 2);
		return (1);
	}	
	if (argc == 1)
	{
		ft_putstr("File name missing.\n", 2);
		return (1);
	}	
	file_name = argv[1];
	file = open(file_name, O_RDWR);
	if (file == -1)
	{
		ft_putstr("Cannot read file.\n", 2);
		return (1);
	}
	read_file(file);
	close(file);
	return (0);
}
