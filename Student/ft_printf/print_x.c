/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:40:08 by tquere            #+#    #+#             */
/*   Updated: 2022/11/12 14:37:00 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>

void	print_x(va_list arg, t_flag *all_flag)
{
	unsigned long long int	i;
	char					*str;

	i = va_arg(arg, unsigned long long int);
	str = long_int_to_hex(i);
	if (str == NULL)
	{
		all_flag->nb_caract = -1;
		return ;
	}
	if (all_flag->flag_hash == 1)
	{
		ft_putstr_fd("0x",1);
		all_flag->nb_caract += 2;
	}
	ft_putstr_fd(str, 1);
	all_flag->nb_caract = all_flag->nb_caract + ft_strlen(str);
	free(str);
}
