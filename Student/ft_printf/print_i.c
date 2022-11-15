/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:40:08 by tquere            #+#    #+#             */
/*   Updated: 2022/11/15 15:46:38 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*print_i(va_list arg, t_flag *all_flag)
{
	long int	i;
	char		*str;
	char		*cat_left;

	i = va_arg(arg, long int);
	str = ft_itoa(i);
	if (all_flag->flag_plus && i >= 0)
	{
		cat_left = ft_strdup("+");
		str = my_strcat(cat_left, str);
	}
	str = put_0(str, all_flag);
	if (str == NULL)
		return (ft_strdup(""));
	return (str);
}
