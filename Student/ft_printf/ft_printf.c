/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:30:31 by tquere            #+#    #+#             */
/*   Updated: 2022/11/12 15:29:12 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include "bonus/ft_printf.h"

void	all_test(const char *str, va_list arg, t_flag *all_flag)
{	
	if (str[all_flag->index] == 'c')
		print_c(arg, all_flag);
	else if (str[all_flag->index] == 's')
		print_s(arg, all_flag);
	else if (str[all_flag->index] == 'p')
		print_p(arg, all_flag);
	else if (str[all_flag->index] == 'd')
		print_d(arg, all_flag);
	else if (str[all_flag->index] == 'i')
		print_i(arg, all_flag);
	else if (str[all_flag->index] == 'u')
		print_u(arg, all_flag);
	else if (str[all_flag->index] == 'x')
		print_x(arg, all_flag);
	else if (str[all_flag->index] == 'X')
		print_xx(arg, all_flag);
	else if (str[all_flag->index] == '%')
	{
		ft_putchar_fd('%', 1);
		all_flag->nb_caract++;
	}
}

static void	print_my_str(const char *str, va_list arg, t_flag *all_flag)
{
	while (str[all_flag->index])
	{
		if (str[all_flag->index] != '%')
		{
			ft_putchar_fd(str[all_flag->index], 1);
			all_flag->nb_caract++;
		}
		else
		{	
			all_flag->index++;
			//all_test(str, arg, &index, all_flag);
			ck_flag(str, arg, all_flag);
		}
		all_flag->index++;
	}
}

int	ft_printf(const char *str, ...)
{	
	va_list		arg;
	t_flag		all_flag;

	all_flag.index = 0;
	all_flag.nb_caract = 0;
	va_start(arg, str);
	print_my_str(str, arg, &all_flag);
	va_end(arg);
	return (all_flag.nb_caract);
}
