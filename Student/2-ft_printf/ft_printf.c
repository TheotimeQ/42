/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:30:31 by tquere            #+#    #+#             */
/*   Updated: 2022/11/11 16:34:23 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

static void	all_test(const char *str, va_list arg, int *index)
{
	if (str[*index] == 'c')
		print_c(arg);
	else if (str[*index] == 's')
		print_s(arg);
	else if (str[*index] == 'p')
		print_p(arg);
	else if (str[*index] == 'd')
		print_d(arg);
	else if (str[*index] == 'i')
		print_i(arg);
	else if (str[*index] == 'u')
		print_u(arg);
	else if (str[*index] == 'x')
		print_x(arg);
	else if (str[*index] == 'X')
		print_xx(arg);
	else if (str[*index] == '%')
		ft_putchar_fd('%', 1);
}

static void	print_my_str(const char *str, va_list arg)
{
	int		index;

	index = 0;
	while (str[index])
	{
		if (str[index] != '%')
			ft_putchar_fd(str[index], 1);
		else
		{	
			index++;
			all_test(str, arg, &index);
		}
		index++;
	}
}

int	ft_printf(const char *str, ...)
{	
	va_list		arg;

	va_start(arg, str);
	print_my_str(str, arg);
	va_end(arg);
	return (0);
}
