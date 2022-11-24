/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:57:12 by tquere            #+#    #+#             */
/*   Updated: 2022/11/24 16:02:04 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*long_int_to_hex(unsigned long int val)
{
	int		index;
	int		index_str;
	int		digit;
	char	*str;

	str = malloc(33 * sizeof(char *));
	if (!str)
		return (NULL);
	ft_bzero(str, 33);
	index = 15;
	index_str = 0;
	while (index >= 0)
	{	
		digit = (val >> 4 * index) & 0xf ;
		str[index_str++] = "0123456789abcdef"[digit];
		index--;
	}
	str[index_str++] = '\0';
	return (str);
}

void	convert_print(long int nb_long, int len_base, char *base, int fd, t_flag *all_flag)
{
	if (nb_long > 0)
	{
		convert_print(nb_long / len_base, len_base, base, fd, all_flag);
		ft_putchar_fd(base[(nb_long % len_base)], 1, all_flag);
	}
}

void	ft_putnbr_base(int nbr, char *base, int fd, t_flag *all_flag)
{
	long int	nb_long;
	int			len_base;

	nb_long = nbr;
	if (nbr < 0)
	{
		nb_long *= -1 ;
		ft_putchar_fd('-', fd, all_flag);
	}
	if (nb_long == 0)
	{
		ft_putchar_fd(&base[0], fd, all_flag);
	}
	if (nb_long > 0)
	{
		convert_print(nb_long, len_base, base, fd, all_flag);
	}
}
