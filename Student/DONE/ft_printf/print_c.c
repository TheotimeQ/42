/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:40:08 by tquere            #+#    #+#             */
/*   Updated: 2022/11/24 15:21:17 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(va_list arg, t_flag *all_flag)
{
	char	c;

	c = va_arg(arg, int);
	ft_putchar_fd(c, 1, all_flag);
}

void	print_s(va_list arg, t_flag *all_flag)
{
	char	*s;

	s = va_arg(arg, char *);
	if (!s)
		ft_putstr_fd("(null)", 1, all_flag);
	else
		ft_putstr_fd(s, 1, all_flag);
}

void	print_pourc(t_flag *all_flag)
{
	ft_putstr_fd("%", 1, all_flag);
}
