/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:42:39 by tquere            #+#    #+#             */
/*   Updated: 2022/11/12 15:56:15 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

#include <stdio.h>

void	print_s(va_list arg, t_flag *all_flag)
{
	char	*s;

	s = va_arg(arg, char *);
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		all_flag->nb_caract += 6;
		return ;
	}


	if (all_flag->flag_point == 1)
	{	
		if ((size_t)all_flag->point_right < ft_strlen(s))
			s = ft_substr(s, 0, all_flag->point_right);
	}
	while()
	{
		//PRINT LES ESPACEgit
	}
	// printf("LEFT : %d  RIGHT : %d ",all_flag->point_left,all_flag->point_right);
	ft_putstr_fd(s, 1);
	all_flag->nb_caract += ft_strlen(s);

}
