/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:23:32 by tquere            #+#    #+#             */
/*   Updated: 2022/07/27 07:56:26 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

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

t_var	print_hex_str(t_var var)
{
	if (ft_strncmp(var.last_str, var.str_prt, 16) != 0)
	{
		print_offset(var.offset, var.option);
		print_hexa(var.str_prt, var.bytes, var.option);
		if (var.option)
			print_str(var.str_prt, var.bytes);
		ft_putstr("\n", 1);
		var.same = 0;
	}
	else
	{	
		if (var.same == 0)
			ft_putstr("*\n", 1);
		var.same = 1;
	}
	var.offset = var.offset + var.bytes;
	var.last_str = ft_strncpy(var.last_str, var.str_prt, 16);
	init_str(var.str_prt);
	init_str(var.rmn_str);
	return (var);
}

t_var	send_rest(t_var var)
{	
	if (var.bytes == 16)
	{	
		var = print_hex_str(var);
	}
	else
	{	
		var.rmn_str = ft_strncpy(var.rmn_str, var.str_prt, var.bytes);
		var.rmn_str[var.bytes] = '\0';
		var.end = var.bytes;
	}
	return (var);
}

t_var	read_file(t_var var)
{	
	char		buffer[20];

	var.str_prt = malloc(sizeof(char) * 19);
	init_str(var.str_prt);
	var.bytes = 16;
	while (var.bytes == 16)
	{	
		if (var.end > 0)
		{	
			var.bytes = read(var.file, buffer, 16 - var.end);
			var.str_prt = ft_strncat(var.rmn_str, buffer, 16 - var.end);
			var.bytes = ft_strlen(var.str_prt);
		}	
		else
		{
			var.bytes = read(var.file, buffer, 16);
			var.str_prt = ft_strncpy(var.str_prt, buffer, var.bytes);
		}
		var = send_rest(var);
	}
	return (var);
}

t_var	print_end(t_var var)
{	
	if (var.end > 0)
	{
		print_offset(var.offset, var.option);
		print_hexa(var.rmn_str, var.end, var.option);
		if (var.option)
			print_str(var.rmn_str, var.end);
		ft_putstr("\n", 1);
	}
	print_offset(var.offset + var.end, var.option);
	ft_putstr("\n", 1);
	return (var);
}
