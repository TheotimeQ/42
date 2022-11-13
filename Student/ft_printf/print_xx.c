/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:44:29 by tquere            #+#    #+#             */
/*   Updated: 2022/11/13 15:48:01 by tquere           ###   ########.fr       */
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
	str = long_int_to_hex(x);
	if (str == NULL)
	{
		all_flag->nb_caract = -1;
		return (ft_strdup(""));
	}
	str = clear_0(str);
	str = put_0(str, all_flag);
	index = 0;
	while (str[index])
	{
		str[index] = ft_toupper(str[index]);
		index++;
	}
	if (all_flag->flag_hash == 1)
	{
		cat_left = ft_strdup("0X");
		str = my_strcat(cat_left, str);
	}
	return (str);
}
