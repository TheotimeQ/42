/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:30:31 by tquere            #+#    #+#             */
/*   Updated: 2022/11/15 14:44:05 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*my_strcat(char *dest, char *src)
{
	size_t	index_dest;
	size_t	index_src;
	char	*new_str;

	if (!dest && src)
		return (src);
	else if (!src && dest)
		return (dest);
	else if (!src && !dest)
		return (NULL);
	new_str = malloc((ft_strlen(dest) + ft_strlen(src) + 1) * sizeof(char));
	index_src = -1;
	index_dest = -1;
	while (dest[++index_dest])
		new_str[index_dest] = dest[index_dest];
	while (src[++index_src])
		new_str[index_dest + index_src] = src[index_src];
	new_str[index_dest + index_src] = '\0';
	free(dest);
	free(src);
	return (new_str);
}

char	*all_test(const char *str, va_list arg, t_flag *all_flag)
{	
	char	*s;

	s = NULL;
	if (str[all_flag->index] == 'c')
		s = print_c(arg, all_flag);
	else if (str[all_flag->index] == 's')
		s = print_s(arg, all_flag);
	else if (str[all_flag->index] == 'p')
		s = print_p(arg, all_flag);
	else if (str[all_flag->index] == 'd')
		s = print_d(arg, all_flag);
	else if (str[all_flag->index] == 'i')
		s = print_i(arg, all_flag);
	else if (str[all_flag->index] == 'u')
		s = print_u(arg, all_flag);
	else if (str[all_flag->index] == 'x')
		s = print_x(arg, all_flag);
	else if (str[all_flag->index] == 'X')
		s = print_xx(arg, all_flag);
	else if (str[all_flag->index] == '%')
		s = print_pourc(all_flag);
	return (s);
}

int	ft_printf(const char *str, ...)
{	
	va_list		arg;
	t_flag		all_flag;

	all_flag.index = 0;
	all_flag.nb_caract = 0;
	va_start(arg, str);
	print_str(str, arg, &all_flag);
	va_end(arg);
	return (all_flag.nb_caract);
}