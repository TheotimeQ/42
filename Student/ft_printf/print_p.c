/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:40:08 by tquere            #+#    #+#             */
/*   Updated: 2022/11/12 14:22:33 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>

void	print_p(va_list arg, t_flag *all_flag)
{
	void				*p;
	long long int		addr;
	char				*str;

	p = va_arg(arg, void *);
	addr = (long long int)p;
	ft_putstr_fd("0x", 1);
	str = long_int_to_hex(addr);
	if (str == NULL)
	{
		all_flag->nb_caract = -1;
		return ;
	}
	all_flag->nb_caract += ft_strlen(str) + 2;
	ft_putstr_fd(str, 1);
	free(str);
}
