/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:17:31 by tquere            #+#    #+#             */
/*   Updated: 2022/11/24 14:40:09 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	reset_flags(t_flag *all_flag)
{
	all_flag->is_null = 0;
	all_flag->flag_hash = 0;
	all_flag->flag_space = 0;
	all_flag->flag_plus = 0;
	all_flag->flag_minus = 0;
	all_flag->flag_zeros = 0;
	all_flag->flag_point = 0;
	all_flag->point_left = -1;
	all_flag->point_right = -1;
	all_flag->error = 0;
}

static void	print_convert(const char *str, va_list arg, t_flag *all_flag)
{	
	char	*s;

	all_flag->index++;
	reset_flags(all_flag);
	s = all_test(str, arg, all_flag);
	if (s != NULL)
	{	
		ft_putstr_fd(s, 1);
		all_flag->nb_caract += ft_strlen(s);
		free(s);
	}
}

void	print_str(const char *str, va_list arg, t_flag *all_flag)
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
			print_convert(str, arg, all_flag);
			if (all_flag->error == 2)
				return ;
		}
		all_flag->index++;
	}
}