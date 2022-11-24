/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:30:31 by tquere            #+#    #+#             */
/*   Updated: 2022/11/24 17:24:11 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	all_test(const char *str, va_list arg, t_flag *all_flag)
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
		print_d(arg, all_flag);
	else if (str[all_flag->index] == 'u')
		print_u(arg, all_flag);
	else if (str[all_flag->index] == 'x')
		print_x(arg, all_flag);
	else if (str[all_flag->index] == 'X')
		print_xx(arg, all_flag);
	else if (str[all_flag->index] == '%')
		print_pourc(all_flag);
	else
		all_flag->error = 2;
}

static void	print_str(const char *str, va_list arg, t_flag *all_flag)
{	
	char	*s;

	s = NULL;
	while (str[all_flag->index])
	{	
		if (str[all_flag->index] != '%')
			ft_putchar_fd(str[all_flag->index], 1, all_flag);
		else
		{	
			all_flag->index++;
			all_test(str, arg, all_flag);
			if (all_flag->error == 2)
				return ;
		}
		all_flag->index++;
	}
}

int	ft_printf(const char *str, ...)
{	
	va_list		arg;
	t_flag		all_flag;

	if (write(1, 0, 0) != 0)
		return (-1);
	all_flag.index = 0;
	all_flag.nb_caract = 0;
	va_start(arg, str);
	print_str(str, arg, &all_flag);
	va_end(arg);
	if (all_flag.error == 1)
		return (-1);
	return (all_flag.nb_caract);
}
