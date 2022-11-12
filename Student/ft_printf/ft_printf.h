/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:10:53 by tquere            #+#    #+#             */
/*   Updated: 2022/11/12 14:45:46 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct s_flag
{
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

}	t_flag;

int			ft_printf(const char *str, ...);
void		print_c(va_list arg, t_flag *all_flag);
void		print_s(va_list arg, t_flag *all_flag);
void		print_p(va_list arg, t_flag *all_flag);
void		print_d(va_list arg, t_flag *all_flag);
void		print_i(va_list arg, t_flag *all_flag);
void		print_u(va_list arg, t_flag *all_flag);
void		print_x(va_list arg, t_flag *all_flag);
void		print_xx(va_list arg, t_flag *all_flag);
char		*long_int_to_hex(unsigned long int val);

#endif
