/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:55:16 by tquere            #+#    #+#             */
/*   Updated: 2022/11/12 14:56:22 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "./ft_printf.h"
#include "ft_printf.h"

static void	ck_flag(const char *str, va_list arg, t_flag *all_flag)
{	
	all_flag->flag_hash = 0;
	all_flag->flag_space = 0;
	all_flag->flag_plus = 0;
	all_flag->flag_minus = 0;
	all_flag->flag_zeros = 0;
	all_flag->flag_point = 0;
	if (str[all_flag->index] == '#' && all_flag->index++)
		all_flag->flag_hash = 1;
	if (str[all_flag->index] == ' ' && all_flag->index++)
		all_flag->flag_space = 1;
	if (str[all_flag->index] == '+' && all_flag->index++)
		all_flag->flag_plus = 1;
	if (str[all_flag->index] == '-' && all_flag->index++)
		all_flag->flag_zeros = 1;
	if (str[all_flag->index] == '.' && all_flag->index++)
	{
		all_flag->flag_point = 1;
		if ('0' <= str[all_flag->index - 1] && str[all_flag->index - 1] <= '9')
		{
			all_flag->point_left = str[all_flag->index - 1] - 48;
			all_flag->index++;
		}
		if ('0' <= str[all_flag->index + 1] && str[all_flag->index + 1] <= '9')
		{
			all_flag->point_left = str[all_flag->index + 1] - 48;
			all_flag->index++;
		}
	}
	all_test(str, arg, all_flag);
}
