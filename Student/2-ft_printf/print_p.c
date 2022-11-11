/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:40:08 by tquere            #+#    #+#             */
/*   Updated: 2022/11/11 16:10:23 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>

void	print_p(va_list arg)
{
	void			*p;
	long int		addr;
	int				index;
	int				digit;
	char			*str;

	index = 15;
	digit = 0;
	p = va_arg(arg, void *);
	addr = (long int)p;
	ft_putstr_fd("0x", 1);
	str = long_int_to_hex(addr);
	ft_putstr_fd(str, 1);
	free(str);
}
