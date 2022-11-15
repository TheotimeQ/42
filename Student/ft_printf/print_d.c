/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:40:08 by tquere            #+#    #+#             */
/*   Updated: 2022/11/15 15:45:09 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*print_d(va_list arg, t_flag *all_flag)
{
	long int	d;
	char		*str;
	char		*cat_left;

	d = va_arg(arg, long int);
	str = ft_itoa(d);
	if (all_flag->flag_plus && d >= 0)
	{
		cat_left = ft_strdup("+");
		str = my_strcat(cat_left, str);
	}
	str = put_0(str, all_flag);
	if (str == NULL)
		return (ft_strdup(""));
	return (str);
}
