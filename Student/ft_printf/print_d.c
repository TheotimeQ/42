/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:40:08 by tquere            #+#    #+#             */
/*   Updated: 2022/11/12 14:25:52 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"

void	print_d(va_list arg, t_flag *all_flag)
{
	long int	d;
	char		*str;

	d = va_arg(arg, long int);
	if (all_flag->flag_plus && d > 0)
	{
		ft_putchar_fd('+', 1);
		all_flag->nb_caract++;
	}
	str = ft_itoa(d);
	if (str == NULL)
	{
		all_flag->nb_caract = -1;
		return ;
	}
	ft_putstr_fd(str, 1);
	all_flag->nb_caract = all_flag->nb_caract + ft_strlen(str);
	free(str);
}
