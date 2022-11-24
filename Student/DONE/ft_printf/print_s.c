/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:42:39 by tquere            #+#    #+#             */
/*   Updated: 2022/11/22 13:39:17 by tquere           ###   ########.fr       */
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
	if (s == NULL)
	{
		all_flag->error = 1;
		return (NULL);
	}
	return (s);
}
