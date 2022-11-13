/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:40:08 by tquere            #+#    #+#             */
/*   Updated: 2022/11/13 14:46:11 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*print_c(va_list arg, t_flag *all_flag)
{
	char	c;
	char	*str;

	c = va_arg(arg, int);
	if (!c)
	{
		all_flag->nb_caract += 1;
		ft_putchar_fd(c,1);
	}
	str = malloc(2 * sizeof(char));
	str[0] = (char)c;
	str[1] = '\0';
	return (str);
}
