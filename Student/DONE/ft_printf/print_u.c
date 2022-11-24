/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:44:41 by tquere            #+#    #+#             */
/*   Updated: 2022/11/24 15:25:48 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_u(va_list arg, t_flag *all_flag)
{
	unsigned int				u;

	u = va_arg(arg, unsigned int);
	ft_putnbr_fd(u, 1, all_flag);
}
