/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:55:16 by tquere            #+#    #+#             */
/*   Updated: 2022/11/12 15:55:37 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft/libft.h"
#include "../ft_printf.h"
#include "ft_printf.h"

#include <stdio.h>

void	ck_flag(const char *str, va_list arg, t_flag *all_flag)
{	
	all_flag->flag_hash = 0;
	all_flag->flag_space = 0;
	all_flag->flag_plus = 0;
	all_flag->flag_minus = 0;
	all_flag->flag_zeros = 0;
	all_flag->flag_point = 0;

	char	c;
	
	c = str[all_flag->index];
	while ('0' <= c && c <= '9')
	{
		all_flag->point_left = str[all_flag->index] - 48;
		all_flag->index++;
		c = str[all_flag->index];
	}
	if (str[all_flag->index] == '.')
	{
		all_flag->flag_point = 1;
		all_flag->index++;
	}

	c = str[all_flag->index];
	while ('0' <= c && c <= '9')
	{
		all_flag->point_right = str[all_flag->index] - 48;
		all_flag->index++;
		c = str[all_flag->index];
	}


	// printf("TEST %c TEST ",str[all_flag->index]);
	
	// //Good
	// if (str[all_flag->index] == '+' && all_flag->index++)
	// 	all_flag->flag_plus = 1;

	// //Good
	// if (str[all_flag->index] == '#' && all_flag->index++)
	// 	all_flag->flag_hash = 1;
	
	// if (str[all_flag->index] == ' ' && all_flag->index++)
	// 	all_flag->flag_space = 1;
	
	// if (str[all_flag->index] == '-' && all_flag->index++)
	// 	all_flag->flag_zeros = 1;

	all_test(str, arg, all_flag);
}
