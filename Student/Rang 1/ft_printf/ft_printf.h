/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:10:53 by tquere            #+#    #+#             */
/*   Updated: 2022/11/29 09:15:33 by tquere           ###   ########.fr       */
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

size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, t_flag *all_flag);
void	ft_putstr_fd(char *s, t_flag *all_flag);
void	ft_putnbr_fd(long long int nb, t_flag *all_flag);
void	ft_putnbr_base(unsigned int nb_long, char *base, t_flag *all_flag);
void	ft_put_un(unsigned long int nb_long, char *base, t_flag *all_flag);
int		ft_printf(const char *str, ...);

#endif
