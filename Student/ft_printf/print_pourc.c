/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pourc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:43:05 by tquere            #+#    #+#             */
/*   Updated: 2022/11/20 16:32:27 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*print_pourc(t_flag *all_flag)
{
	char	*s;

	all_flag->point_right = 0;
	s = ft_strdup("%");
	s = put_0(s, all_flag);
	return (s);
}
