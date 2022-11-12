/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:57:12 by tquere            #+#    #+#             */
/*   Updated: 2022/11/12 13:23:23 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>

char	*long_int_to_hex(unsigned long int val)
{
	int		index;
	int		index_str;
	int		digit;
	char	*str;

	str = malloc(33 * sizeof(char *));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, 33);
	index = 15;
	index_str = 0;
	while (index >= 0 && digit == 0)
	{	
		digit = (val >> 4 * index) & 0xf ;
		index--;
	}
	str[index_str++] = "0123456789abcdef"[digit];
	while (index >= 0)
	{	
		digit = (val >> 4 * index) & 0xf ;
		str[index_str++] = "0123456789abcdef"[digit];
		index--;
	}
	str[index_str++] = '\0';
	return (str);
}
