/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:42:39 by tquere            #+#    #+#             */
/*   Updated: 2022/11/15 15:41:48 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*print_s(va_list arg, t_flag *all_flag)
{
	char	*s;

	s = va_arg(arg, char *);
	if (!s)
	{	
		return (ft_strdup("(null)"));
	}
	if (all_flag->point_right < 0)
		all_flag->point_right = 0;
	if (all_flag->flag_point == 1)
	{	
		if ((size_t)all_flag->point_right < ft_strlen(s) - 1)
			s = ft_substr(s, 0, all_flag->point_right);
	}
	return (ft_strdup(s));
}
