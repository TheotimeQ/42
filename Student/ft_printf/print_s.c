/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:42:39 by tquere            #+#    #+#             */
/*   Updated: 2022/11/19 13:35:14 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*print_s(va_list arg, t_flag *all_flag)
{
	char	*s;

	s = va_arg(arg, char *);
	if (!s)
		s = ft_strdup("(null)");
	else
		s = ft_strdup(s);
	if (all_flag->point_right < 0)
		all_flag->point_right = 0;
	if (all_flag->flag_point == 1)
	{	
		if ((size_t)all_flag->point_right < ft_strlen(s))
		{	
			s[all_flag->point_right] = '\0';
			return (s);
		}
	}
	return (s);
}
