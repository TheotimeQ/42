/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:40:08 by tquere            #+#    #+#             */
/*   Updated: 2022/11/20 16:19:08 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*print_c(va_list arg, t_flag *all_flag)
{
	char	c;
	char	*str;

	c = va_arg(arg, int);
	if (all_flag->point_left > 0 && !c)
	{	
		while (!all_flag->flag_minus && --all_flag->point_left > 0)
		{
			ft_putchar_fd(' ', 1);
			all_flag->nb_caract++;
		}
	}
	if (!c)
	{
		all_flag->nb_caract += 1;
		ft_putchar_fd(c, 1);
	}
	if (all_flag->point_left > 0 && !c)
	{	
		while (all_flag->flag_minus && --all_flag->point_left > 0)
		{
			ft_putchar_fd(' ', 1);
			all_flag->nb_caract++;
		}
	}
	str = malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = (char)c;
	str[1] = '\0';
	return (str);
}
