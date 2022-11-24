/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:40:08 by tquere            #+#    #+#             */
/*   Updated: 2022/11/24 16:59:10 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_d(va_list arg, t_flag *all_flag)
{
	long int	d;
	char		*str;

	d = va_arg(arg, long int);
	str = ft_itoa(d);
	if (str == NULL)
	{
		all_flag->error = 1;
		return ;
	}
	ft_putstr_fd(str, 1, all_flag);
	free(str);
}
