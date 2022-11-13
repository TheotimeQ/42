/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:30:31 by tquere            #+#    #+#             */
/*   Updated: 2022/11/13 15:24:52 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

#define BONUS 1

char	*all_test(const char *str, va_list arg, t_flag *all_flag)
{	
	char	*s;

	s = NULL;
	if (str[all_flag->index] == 'c')
		s = print_c(arg, all_flag);
	else if (str[all_flag->index] == 's')
		s = print_s(arg);
	else if (str[all_flag->index] == 'p')
		s = print_p(arg, all_flag);
	else if (str[all_flag->index] == 'd')
		s = print_d(arg, all_flag);
	else if (str[all_flag->index] == 'i')
		s = print_i(arg, all_flag);
	else if (str[all_flag->index] == 'u')
		s = print_u(arg, all_flag);
	else if (str[all_flag->index] == 'x')
		s = print_x(arg, all_flag);
	else if (str[all_flag->index] == 'X')
		s = print_xx(arg, all_flag);
	else if (str[all_flag->index] == '%')
	{
		ft_putchar_fd('%', 1);
		all_flag->nb_caract++;
	}
	return (s);
}

static void	print_my_str(const char *str, va_list arg, t_flag *all_flag)
{	
	char	*s;

	s = NULL;
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
			if (BONUS)
				s = ck_flag(str, arg, all_flag);
			else
				s = all_test(str, arg, all_flag);
			if (s != NULL)
			{	
				ft_putstr_fd(s, 1);
				all_flag->nb_caract += ft_strlen(s);
				free(s);
			}
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
