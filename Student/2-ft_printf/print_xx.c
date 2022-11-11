/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:44:29 by tquere            #+#    #+#             */
/*   Updated: 2022/11/11 16:10:23 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>

void	print_xx(va_list arg)
{
	int					index;
	unsigned long int	i;
	char				*str;

	i = va_arg(arg, unsigned long int);
	str = long_int_to_hex(i);
	index = 0;
	while (str[index])
	{
		str[index] = ft_toupper(str[index]);
		index++;
	}
	ft_putstr_fd(str, 1);
	free(str);
}
