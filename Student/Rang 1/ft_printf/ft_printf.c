/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:30:31 by tquere            #+#    #+#             */
/*   Updated: 2022/11/26 17:34:57 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	all_test(const char *str, va_list arg, t_flag *all_flag)
{	
	int fd;

	fd = all_flag->fd;
	if (str[all_flag->index] == 'c')
		ft_putchar_fd(va_arg(arg, int), fd, all_flag);
	else if (str[all_flag->index] == 's')
		ft_putstr_fd(va_arg(arg, char *), fd, all_flag);
	else if (str[all_flag->index] == 'p')
	{
		ft_putstr_fd("0x", fd, all_flag);
		ft_putnbr_base(va_arg(arg, long long int),"0123456789abcdef", fd, all_flag);
	}
	else if (str[all_flag->index] == 'd'|| str[all_flag->index] == 'i')
		ft_putnbr_fd(va_arg(arg, long int), fd, all_flag);
	else if (str[all_flag->index] == 'u')
		ft_putnbr_fd(va_arg(arg, unsigned int), fd, all_flag);
	else if (str[all_flag->index] == 'x')
		ft_putnbr_base(va_arg(arg, unsigned int),"0123456789abcdef", fd, all_flag);
	else if (str[all_flag->index] == 'X')
		ft_putnbr_base(va_arg(arg, unsigned int),"0123456789ABCDEF", fd, all_flag);
	if (str[all_flag->index] == '%')
		ft_putchar_fd('%', fd, all_flag);
	else
		all_flag->error = 2;
}

static void	print_str(const char *str, va_list arg, t_flag *all_flag)
{	
	while (str[all_flag->index])
	{	
		if (str[all_flag->index] != '%')
			ft_putchar_fd(str[all_flag->index], 1, all_flag);
		else
		{	
			all_flag->index++;
			all_test(str, arg, all_flag);
			if (all_flag->error == 2)
				return ;
		}
		all_flag->index++;
	}
}

int	ft_printf(const char *str, ...)
{	
	va_list		arg;
	t_flag		all_flag;

	if (write(1, 0, 0) != 0)
		return (-1);
	all_flag.index = 0;
	all_flag.nb_caract = 0;
	va_start(arg, str);
	print_str(str, arg, &all_flag);
	va_end(arg);
	if (all_flag.error == 1)
		return (-1);
	return (all_flag.nb_caract);
}

#include <stdio.h>

// #define ARGS "%c",'a'
// #define ARGS "%s","COUCOU MAMAN"
// #define ARGS "%p",(void *)21354
// #define ARGS "%d",1237895
// #define ARGS "%i",125875
// #define ARGS "%u",(unsigned int)124878
// #define ARGS "%x",1258
// #define ARGS "%X",459786
// #define ARGS "%q"


// int main()
// {
// 	printf("| %d |\n",ft_printf(ARGS));
// 	printf("| %d |\n",printf(ARGS));

// }
