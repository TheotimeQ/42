/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:40:08 by tquere            #+#    #+#             */
/*   Updated: 2022/11/11 16:10:23 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"

void	print_d(va_list arg)
{
	double		d;
	double		decimal_part;
	char		*str;

	d = va_arg(arg, double);
	str = ft_itoa(d);
	ft_putstr_fd(str, 1);
	decimal_part = d - ((long)d);
	ft_putchar_fd('.', 1);
	if (decimal_part < 0)
		decimal_part *= -1;
	str = ft_itoa(decimal_part * 1000000);
	ft_putstr_fd(str, 1);
	free(str);
}
