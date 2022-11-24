/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:10:53 by tquere            #+#    #+#             */
/*   Updated: 2022/11/24 14:39:13 by tquere           ###   ########.fr       */
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
	int				is_null;
	int				flag_hash;
	int				flag_space;
	int				flag_plus;
	int				flag_minus;
	int				flag_zeros;
	int				flag_point;
	int				point_left;
	int				point_right;
	int				nb_caract;
	int				index;
	int				error;

}	t_flag;

void		ft_putchar_fd(char c, int fd, t_flag *all_flag);
size_t		ft_strlen(const char *s);

int			ft_printf(const char *str, ...);
char		*print_c(va_list arg, t_flag *all_flag);
char		*print_s(va_list arg, t_flag *all_flag);
char		*print_p(va_list arg, t_flag *all_flag);
char		*print_d(va_list arg, t_flag *all_flag);
char		*print_i(va_list arg, t_flag *all_flag);
char		*print_u(va_list arg, t_flag *all_flag);
char		*print_x(va_list arg, t_flag *all_flag);
char		*print_xx(va_list arg, t_flag *all_flag);
char		*print_pourc(t_flag *all_flag);
char		*long_int_to_hex(unsigned long int val);
char		*clear_0(char *str);
char		*all_test(const char *str, va_list arg, t_flag *all_flag);
void		print_str(const char *str, va_list arg, t_flag *all_flag);
char		*my_strcat(char *dest, char *src);

#endif
