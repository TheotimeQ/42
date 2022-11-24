/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:40:08 by tquere            #+#    #+#             */
/*   Updated: 2022/11/24 17:21:28 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_x(va_list arg, t_flag *all_flag)
{
	unsigned int			x;

	x = va_arg(arg, unsigned int);
	long_int_to_hex(x, 1, all_flag);
}

void	print_xx(va_list arg, t_flag *all_flag)
{
	unsigned int			x;

	x = va_arg(arg, unsigned int);
	long_int_to_hex_2(x, 1, all_flag);
}
