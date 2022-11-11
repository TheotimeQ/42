/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:42:39 by tquere            #+#    #+#             */
/*   Updated: 2022/11/11 16:10:23 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

void	print_s(va_list arg)
{
	char	*s;

	s = va_arg(arg, char *);
	ft_putstr_fd(s, 1);
}
