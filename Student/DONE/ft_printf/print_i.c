/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:40:08 by tquere            #+#    #+#             */
/*   Updated: 2022/11/22 13:40:27 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*print_i(va_list arg, t_flag *all_flag)
{
	long int	i;
	char		*str;

	i = va_arg(arg, long int);
	str = ft_itoa(i);
	if (str == NULL)
	{
		all_flag->error = 1;
		return (NULL);
	}
	return (str);
}
