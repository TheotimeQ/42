/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:10:53 by tquere            #+#    #+#             */
/*   Updated: 2022/11/11 16:13:38 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	print_c(va_list arg);
void	print_s(va_list arg);
void	print_p(va_list arg);
void	print_d(va_list arg);
void	print_i(va_list arg);
void	print_u(va_list arg);
void	print_x(va_list arg);
void	print_xx(va_list arg);
char	*long_int_to_hex(unsigned long int val);

#endif
