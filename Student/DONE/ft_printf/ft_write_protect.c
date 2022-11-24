/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_protect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:17:31 by tquere            #+#    #+#             */
/*   Updated: 2022/11/24 15:34:58 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

void	ft_putchar_fd(char c, int fd, t_flag *all_flag)
{	
	if (write(1, 0, 0) != 0)
	{
		all_flag->error = 1;
		return ;
	}
	write(fd, &c, 1);
	all_flag->nb_caract += 1;
}

void	ft_putstr_fd(char *str, int fd, t_flag *all_flag)
{
	size_t		len;

	if (!str)
		return ;
	len = ft_strlen(str);
	if (write(1, 0, 0) != 0)
	{
		all_flag->error = 1;
		return ;
	}
	write(fd, &str, len);
	all_flag->nb_caract += len;
}

void	ft_putnbr_fd(int nb, int fd, t_flag *all_flag)
{
	if (nb < 0)
	{
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, fd, all_flag);
		ft_putnbr(nb % 10, fd, all_flag);
	}
	else
		ft_putchar_fd(nb + '0', fd, all_flag);
}
