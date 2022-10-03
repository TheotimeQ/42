/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:38:04 by tquere            #+#    #+#             */
/*   Updated: 2022/07/19 15:38:09 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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

void	no_file_error(int file, char *file_name)
{
	if (file == -1)
	{
		ft_putstr("cat: ", 2);
		ft_putstr(file_name, 2);
		ft_putstr(": ", 2);
		ft_putstr(strerror(errno), 2);
		ft_putstr("\n", 2);
	}
}

void	print_name(int argc, char *base)
{
	if (argc > 2)
	{
		ft_putstr("==> ", 1);
		ft_putstr(base, 2);
		ft_putstr(" <==\n", 2);
	}
}

long int	convert_int(char *str)
{	
	long int	nb;
	long int	i;

	i = 0;
	nb = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
	{
		ft_putstr("tail: illegal offset -- ", 2);
		ft_putstr(str, 2);
		return (-1);
	}
	return (nb);
}

long int	get_file_size(int file)
{
	char				buffer[30];
	long int			size;

	size = 0;
	while (read(file, buffer, 1) > 0)
	{
		size++;
	}
	close(file);
	return (size);
}
