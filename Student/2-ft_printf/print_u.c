/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:44:41 by tquere            #+#    #+#             */
/*   Updated: 2022/11/11 16:10:23 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>

void	print_u(va_list arg)
{
	double		u;
	double		decimal_part;
	char		*str;

	u = va_arg(arg, double);
	str = ft_itoa(u);
	ft_putstr_fd(str, 1);
	decimal_part = u - ((long)u);
	ft_putchar_fd('.', 1);
	if (decimal_part < 0)
		decimal_part *= -1;
	str = ft_itoa(decimal_part * 1000000);
	ft_putstr_fd(str, 1);
	free(str);
}
