/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:40:08 by tquere            #+#    #+#             */
/*   Updated: 2022/11/24 15:56:11 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_x(va_list arg, t_flag *all_flag)
{
	unsigned int			x;

	x = va_arg(arg, unsigned int);


	ft_putstr_fd('NO', 1, all_flag);
}

static int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c = c - 32 ;
	return (c);
}

void	print_xx(va_list arg, t_flag *all_flag)
{
	unsigned int			x;


	x = va_arg(arg, unsigned int);

	ft_putstr_fd('NO', 1, all_flag);
}

void	print_p(va_list arg, t_flag *all_flag)
{
	void				*p;
	long long int		addr;

	p = va_arg(arg, void *);
	addr = (long long int)p;
	ft_putstr_fd("0x", 1, all_flag);


	ft_putstr_fd('NO', 1, all_flag);
}
