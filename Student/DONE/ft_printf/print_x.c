/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:40:08 by tquere            #+#    #+#             */
/*   Updated: 2022/11/24 15:30:28 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_x(va_list arg, t_flag *all_flag)
{
	unsigned int			x;
	char					*str;

	x = va_arg(arg, unsigned int);
	str = long_int_to_hex(x);
	str = clear_0(str);
	if (str == NULL)
		all_flag->error = 1;
	ft_putstr_fd(str, 1, all_flag);
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
	char					*str;
	int						index;

	x = va_arg(arg, unsigned int);
	str = long_int_to_hex(x);
	str = clear_0(str);
	index = -1;
	while (str[++index])
		str[index] = ft_toupper(str[index]);
	if (str == NULL)
		all_flag->error = 1;
	ft_putstr_fd(str, 1, all_flag);
}

void	print_p(va_list arg, t_flag *all_flag)
{
	void				*p;
	long long int		addr;
	char				*str;

	p = va_arg(arg, void *);
	addr = (long long int)p;
	ft_putstr_fd("0x", 1, all_flag);
	str = long_int_to_hex(addr);
	if (str == NULL)
		all_flag->error = 1;
	str = clear_0(str);
	ft_putstr_fd(str, 1, all_flag);
}
