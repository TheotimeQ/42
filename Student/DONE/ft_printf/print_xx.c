/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:44:29 by tquere            #+#    #+#             */
/*   Updated: 2022/11/24 14:40:31 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c = c - 32 ;
	return (c);
}

char	*print_xx(va_list arg, t_flag *all_flag)
{
	unsigned int			x;
	char					*str;
	int						index;

	x = va_arg(arg, unsigned int);
	str = long_int_to_hex(x);
	str = clear_0(str);
	index = -1;
	while (str[++index])
		str[index] = ft_toupper(str[index]);
	if (str == NULL)
	{
		all_flag->error = 1;
		return (NULL);
	}
	return (str);
}
