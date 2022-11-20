/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:40:08 by tquere            #+#    #+#             */
/*   Updated: 2022/11/15 15:45:19 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*print_x(va_list arg, t_flag *all_flag)
{
	unsigned int			x;
	char					*str;
	char					*cat_left;

	x = va_arg(arg, unsigned int);
	str = long_int_to_hex(x);
	str = clear_0(str);
	str = put_0(str, all_flag);
	if (all_flag->flag_hash == 1)
	{
		cat_left = ft_strdup("0x");
		str = my_strcat(cat_left, str);
	}
	if (str == NULL)
	{
		return (ft_strdup(""));
	}
	return (str);
}
