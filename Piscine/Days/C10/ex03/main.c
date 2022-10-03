/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:57:22 by tquere            #+#    #+#             */
/*   Updated: 2022/09/19 15:42:08 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>

int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
void	init_str(char *str);
int		ft_strlen(char *str);

void	ft_putstr(char *str, int output);
void	ft_putchar(char c, int output);
void	print_offset(int nb, int option);
void	print_hexa(char *str, int size, int option);

void	print_str(char *str, int size);

typedef struct s_var
{
	int		file;
	int		offset;
	int		end;
	int		option;
	int		same;
	int		index;
	int		bytes;
	int		size_rmn;
	char	*rmn_str;
	char	*last_str;
	char	*str_prt;

}	t_var;

t_var	print_hex_str(t_var var);
t_var	send_rest(t_var var);
t_var	read_file(t_var var);
t_var	print_end(t_var var);

void	print_error(char *str)
{
	ft_putstr("hexdump: ", 2);
	ft_putstr(str, 2);
	ft_putstr(": ", 2);
	ft_putstr(strerror(errno), 2);
	ft_putstr("\n", 2);
	if (errno == 2)
	{
		ft_putstr("hexdump: ", 2);
		ft_putstr(str, 2);
		ft_putstr(": Bad file descriptor\n", 2);
	}
}

void	loop_threw_file(int argc, char **argv, t_var var)
{	
	char		*base;

	while (var.index < argc)
	{
		base = basename(argv[var.index]);
		var.file = open(argv[var.index], O_RDWR);
		if (var.file == -1)
		{
			print_error(argv[var.index]);
		}
		else
		{
			var = read_file(var);
			close(var.file);
		}
		var.index++;
	}
	if (var.end > 0)
		var = print_end(var);
}

void	open_stdin(t_var var)
{	
	int			file;
	char		buffer[1];

	init_str(var.str_prt);
	file = open(STDIN_FILENO, O_RDWR);
	while (read(STDIN_FILENO, buffer, 1) > 0)
	{	
		var.str_prt = ft_strncat(var.rmn_str, buffer, 1);
		var.bytes = ft_strlen(var.str_prt);
		var = send_rest(var);
	}
	if (var.end > 0)
		var = print_end(var);
	close(file);
}

t_var	init_struct(void)
{
	t_var		var;

	var.option = 0;
	var.same = 0;
	var.index = 1;
	var.offset = 0;
	var.file = 0;
	var.end = 0;
	var.bytes = 0;
	var.size_rmn = 0;
	var.rmn_str = malloc(19);
	var.last_str = malloc(19);
	var.str_prt = malloc(19);
	init_str(var.str_prt);
	init_str(var.last_str);
	init_str(var.rmn_str);
	return (var);
}

int	main(int argc, char **argv)
{	
	t_var		var;

	var = init_struct();
	if (argc == 1)
	{
		open_stdin(var);
		return (0);
	}
	if (argv[1][0] == '-' && argv[1][1] == 'C')
	{
		var.index = 2;
		var.option = 1;
		if (argc == 2)
		{
			open_stdin(var);
			return (0);
		}
	}
	loop_threw_file(argc, argv, var);
	return (1);
}
