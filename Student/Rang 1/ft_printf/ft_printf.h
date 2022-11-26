/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:10:53 by tquere            #+#    #+#             */
/*   Updated: 2022/11/26 17:20:25 by zelinsta         ###   ########.fr       */
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
	int				fd;
	int				nb_caract;
	int				index;
	int				error;

}	t_flag;

// void		long_int_to_hex(unsigned long int val, int fd, t_flag *all_flag);
// void		long_int_to_hex_2(unsigned long int val, int fd, t_flag *all_flag);
// char		*ft_itoa(int n);

size_t		ft_strlen(const char *s);
void		ft_putchar_fd(char c, int fd, t_flag *all_flag);
void		ft_putstr_fd(char *s, int fd, t_flag *all_flag);
void		ft_putnbr_fd(int nb, int fd, t_flag *all_flag);
void		ft_putnbr_base(int nbr, char *base,int fd, t_flag *all_flag);

int			ft_printf(const char *str, ...);
// void		print_pourc(t_flag *all_flag);
// void		print_c(va_list arg, t_flag *all_flag);
// void		print_s(va_list arg, t_flag *all_flag);
// void		print_d(va_list arg, t_flag *all_flag);
// void		print_i(va_list arg, t_flag *all_flag);
// void		print_p(va_list arg, t_flag *all_flag);
// void		print_u(va_list arg, t_flag *all_flag);
// void		print_x(va_list arg, t_flag *all_flag);
// void		print_xx(va_list arg, t_flag *all_flag);

#endif
