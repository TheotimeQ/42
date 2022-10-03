/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 23:08:32 by tquere            #+#    #+#             */
/*   Updated: 2022/07/28 10:57:35 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>

#include <stdio.h>

void			ft_putstr(char *str, int output);
void			no_file_error(int file, char *file_name);
void			print_name(int argc, char *base);
int				convert_int(char *str);
long int		get_file_size(int file);
void			open_stdin_2(int nb_from_end);

void	got_to_end_and_print(char *file_name, long int size, int nb_from_end)
{
	char				buffer[30];
	int					file;

	file = open(file_name, O_RDWR);
	while (read(file, buffer, 1) > 0 && size - 1 > nb_from_end)
	{
		size--;
	}
	while (read(file, buffer, 1) > 0 && size > 0)
	{	
		write(1, buffer, 1);
		size--;
	}
	close(file);
}

void	loop_file(int argc, char **argv, int index, long int nb_from_end)
{	
	char					*base;
	char					*file_name;
	int						file;
	long int				size;

	while (index < argc)
	{
		file_name = argv[index++];
		base = basename(file_name);
		file = open(file_name, O_RDONLY);
		no_file_error(file, file_name);
		if (file != -1)
		{	
			if (argc > 4 && nb_from_end >= 0)
				print_name(argc, base);
			if (argc > 2 && nb_from_end == -1)
				print_name(argc, base);
			size = get_file_size(file);
			if (nb_from_end < 0)
				nb_from_end = size;
			got_to_end_and_print(file_name, size, nb_from_end);
			if (index != argc)
				ft_putstr("\n", 1);
		}
	}
}

void	open_stdin_1(void)
{	
	int			file;
	char		buffer[30];

	file = open(STDIN_FILENO, O_RDWR);
	while (read(STDIN_FILENO, buffer, 1) > 0)
	{
		write (1, &buffer[0], 1);
	}
	close(file);
}

void	check_arg(int argc, char **argv, int nb_from_end)
{
	if (argc <= 2)
	{
		ft_putstr("tail: option requires an argument -- c\n", 2);
		ft_putstr("usage: tail [-F | -f | -r] [-q] ", 2);
		ft_putstr("[-b # | -c # | -n #] [file ...]\n", 2);
		return ;
	}
	if (argc == 3)
	{	
		nb_from_end = convert_int(argv[2]);
		if (nb_from_end < 0)
			return ;
		open_stdin_2(nb_from_end);
		return ;
	}
	else
	{
		nb_from_end = convert_int(argv[2]);
		if (nb_from_end < 0)
			return ;
		loop_file(argc, argv, 3, nb_from_end);
		return ;
	}
}

int	main(int argc, char **argv)
{	
	long int	nb_from_end;

	nb_from_end = 0;
	if (argc == 1)
	{
		open_stdin_1();
		return (0);
	}
	if (argv[1][0] != '-')
	{
		loop_file(argc, argv, 1, -1);
		return (1);
	}
	if (argv[1][0] == '-' && argv[1][1] == 'c')
	{	
		check_arg(argc, argv, nb_from_end);
	}
	return (0);
}
