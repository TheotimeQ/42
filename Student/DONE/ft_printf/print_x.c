/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:40:08 by tquere            #+#    #+#             */
/*   Updated: 2022/11/22 13:39:03 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*print_x(va_list arg, t_flag *all_flag)
{
	unsigned int			x;
	char					*str;

	x = va_arg(arg, unsigned int);
	str = long_int_to_hex(x);
	str = clear_0(str);
	if (str == NULL)
	{
		all_flag->error = 1;
		return (NULL);
	}
	return (str);
}
