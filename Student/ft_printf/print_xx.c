/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:44:29 by tquere            #+#    #+#             */
/*   Updated: 2022/11/12 14:37:14 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>

void	print_xx(va_list arg, t_flag *all_flag)
{
	int					index;
	unsigned long int	i;
	char				*str;

	i = va_arg(arg, unsigned long int);
	str = long_int_to_hex(i);
	if (str == NULL)
	{
		all_flag->nb_caract = -1;
		return ;
	}
	index = 0;
	while (str[index])
	{
		str[index] = ft_toupper(str[index]);
		index++;
	}
	if (all_flag->flag_hash == 1)
	{
		ft_putstr_fd("0X",1);
		all_flag->nb_caract += 2;
	}
	ft_putstr_fd(str, 1);
	all_flag->nb_caract += ft_strlen(str);
	free(str);
}
