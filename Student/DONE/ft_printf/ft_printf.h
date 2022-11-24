/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:10:53 by tquere            #+#    #+#             */
/*   Updated: 2022/11/24 15:54:59 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flag
{	
	int				nb_caract;
	int				index;
	int				error;

}	t_flag;

char		*long_int_to_hex(unsigned long int val);
char		*clear_0(char *str);

size_t		ft_strlen(const char *s);
void		ft_putchar_fd(char c, int fd, t_flag *all_flag);
void		ft_putstr_fd(char *s, int fd, t_flag *all_flag);
void		ft_putnbr_fd(int nb, int fd, t_flag *all_flag);

int			ft_printf(const char *str, ...);
void		print_pourc(t_flag *all_flag);
void		print_c(va_list arg, t_flag *all_flag);
void		print_s(va_list arg, t_flag *all_flag);
void		print_d(va_list arg, t_flag *all_flag);
void		print_i(va_list arg, t_flag *all_flag);
void		print_p(va_list arg, t_flag *all_flag);
void		print_u(va_list arg, t_flag *all_flag);
void		print_x(va_list arg, t_flag *all_flag);
void		print_xx(va_list arg, t_flag *all_flag);

#endif
