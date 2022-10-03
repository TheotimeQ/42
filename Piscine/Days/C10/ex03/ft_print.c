/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:23:01 by tquere            #+#    #+#             */
/*   Updated: 2022/07/27 07:55:21 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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

void	ft_putchar(char c, int output)
{
	write(output, &c, 1);
}

void	print_offset(int nb, int option)
{
	char		*str;
	int			index;

	str = malloc(sizeof(int) * 8);
	index = 8;
	if (option == 0)
		index = 7;
	str[index--] = '\0';
	while (nb > 0)
	{	
		str[index--] = "0123456789abcdef"[nb % 16];
		nb = nb / 16;
	}
	while (index != -1)
	{	
		str[index--] = '0';
	}
	ft_putstr(str, 1);
	free(str);
}

void	print_space(int index, int option)
{
	while (index < 16)
	{	
		ft_putstr("  ", 1);
		index++;
		if ((index == 8 || index == 16) && option)
			ft_putstr("  ", 1);
		else if (index != 16)
			ft_putstr(" ", 1);
	}
}

void	print_hexa(char *str, int size, int option)
{
	int			index;
	int			digit;
	char		char_to_print;

	ft_putstr(" ", 1);
	if (option)
		ft_putstr(" ", 1);
	index = 0;
	while (index < size)
	{	
		digit = (*(str + index) >> 4) & 0xf;
		char_to_print = "0123456789abcdef"[digit];
		ft_putchar(char_to_print, 1);
		digit = (*(str + index)) & 0xf;
		char_to_print = "0123456789abcdef"[digit];
		ft_putchar(char_to_print, 1);
		index++;
		if ((index == 8 || index == 16) && option)
			ft_putstr("  ", 1);
		else if (index != 16)
			ft_putstr(" ", 1);
	}
	print_space(index, option);
}
