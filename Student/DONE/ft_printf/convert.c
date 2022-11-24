/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:57:12 by tquere            #+#    #+#             */
/*   Updated: 2022/11/24 17:25:18 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	*ft_memset(void *b, int c, size_t len)
{
	size_t		index;
	char		*str;

	str = b;
	index = 0;
	while (index < len)
	{
		str[index] = (unsigned char)c;
		index++;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	long_int_to_hex(unsigned long int val, int fd, t_flag *all_flag)
{
	int		index;
	int		index_str;
	int		digit;
	char	*str;

	str = malloc(33 * sizeof(char));
	if (!str)
	{
		all_flag->error = 1;
		return ;
	}
	ft_bzero(str, 33);
	index = 15;
	index_str = 0;
	while (index >= 0)
	{	
		digit = (val >> 4 * index--) & 0xf ;
		str[index_str++] = "0123456789abcdef"[digit];
	}
	str[index_str++] = '\0';
	index = 0;
	while (str[index] && str[index] == '0' && index < (int)ft_strlen(str) - 1)
		index++;
	ft_putstr_fd(str + index, fd, all_flag);
	free(str);
}

void	long_int_to_hex_2(unsigned long int val, int fd, t_flag *all_flag)
{
	int		index;
	int		index_str;
	int		digit;
	char	*str;

	str = malloc(33 * sizeof(char));
	if (!str)
	{
		all_flag->error = 1;
		return ;
	}
	ft_bzero(str, 33);
	index = 15;
	index_str = 0;
	while (index >= 0)
	{	
		digit = (val >> 4 * index--) & 0xf ;
		str[index_str++] = "0123456789ABCDEF"[digit];
	}
	str[index_str++] = '\0';
	index = 0;
	while (str[index] && str[index] == '0' && index < (int)ft_strlen(str) - 1)
		index++;
	ft_putstr_fd(str + index, fd, all_flag);
	free(str);
}
