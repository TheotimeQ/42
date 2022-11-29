/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_base_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:14:23 by tquere            #+#    #+#             */
/*   Updated: 2022/11/29 09:18:04 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	c_print(unsigned long int nb, int len, char *base, t_flag *all_flag)
{
	if (nb > 0)
	{
		c_print(nb / len, len, base, all_flag);
		ft_putchar_fd(base[(nb % len)], all_flag);
	}
}

void	ft_put_un(unsigned long int nb_long, char *base, t_flag *all_flag)
{
	int			len_base;

	len_base = ft_strlen(base);
	ft_putstr_fd("0x", all_flag);
	if (nb_long == 0)
	{
		write(all_flag->fd, &base[0], 1);
		all_flag->nb_caract += 1;
	}
	if (nb_long > 0)
	{
		c_print(nb_long, len_base, base, all_flag);
	}
}
