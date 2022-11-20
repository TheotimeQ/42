/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:44:29 by tquere            #+#    #+#             */
/*   Updated: 2022/11/20 17:12:41 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*print_xx(va_list arg, t_flag *all_flag)
{
	unsigned int			x;
	char					*str;
	int						index;
	char					*cat_left;

	x = va_arg(arg, unsigned int);
	if (all_flag->flag_point && all_flag->point_right <= 0 && x == 0)
		str = ft_strdup("");
	else
		str = long_int_to_hex(x);
	str = clear_0(str);
	str = put_0(str, all_flag);
	index = -1;
	while (str[++index])
		str[index] = ft_toupper(str[index]);
	if (all_flag->flag_hash == 1 && x > 0)
	{
		cat_left = ft_strdup("0X");
		str = my_strcat(cat_left, str);
	}
	if (str == NULL)
	{
		// all_flag->error = 1;
		return (ft_strdup(""));
	}
	return (str);
}
