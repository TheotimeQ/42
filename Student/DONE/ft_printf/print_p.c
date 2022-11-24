/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:40:08 by tquere            #+#    #+#             */
/*   Updated: 2022/11/22 13:40:16 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*print_p(va_list arg, t_flag *all_flag)
{
	void				*p;
	long long int		addr;
	char				*str;
	char				*cat_left;

	p = va_arg(arg, void *);
	addr = (long long int)p;
	str = long_int_to_hex(addr);
	if (str == NULL)
	{
		all_flag->error = 1;
		return (NULL);
	}
	str = clear_0(str);
	cat_left = ft_strdup("0x");
	str = my_strcat(cat_left, str);
	if (str == NULL || cat_left == NULL)
	{
		all_flag->error = 1;
		return (NULL);
	}
	all_flag->point_right = 2;
	return (str);
}
