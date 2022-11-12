/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:40:08 by tquere            #+#    #+#             */
/*   Updated: 2022/11/12 14:22:33 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"

void	print_i(va_list arg, t_flag *all_flag)
{
	long int	i;
	char		*str;

	i = va_arg(arg, long int);
	str = ft_itoa(i);
	if (str == NULL)
	{
		all_flag->nb_caract = -1;
		return ;
	}
	ft_putstr_fd(str, 1);
	all_flag->nb_caract += ft_strlen(str);
	free(str);
}
