/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:57:12 by tquere            #+#    #+#             */
/*   Updated: 2022/11/24 15:33:22 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int				index;
	char			*str;

	if (s == NULL)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
	{
		str = malloc(1);
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	index = start - 1;
	while (++index - start < len)
		str[index - start] = s[index];
	str[index - start] = '\0';
	return (str);
}

char	*long_int_to_hex(unsigned long int val)
{
	int		index;
	int		index_str;
	int		digit;
	char	*str;

	str = malloc(33 * sizeof(char *));
	if (!str)
		return (NULL);
	ft_bzero(str, 33);
	index = 15;
	index_str = 0;
	while (index >= 0)
	{	
		digit = (val >> 4 * index) & 0xf ;
		str[index_str++] = "0123456789abcdef"[digit];
		index--;
	}
	str[index_str++] = '\0';
	return (str);
}

char	*clear_0(char *str)
{
	int		index;
	char	*new_str;

	if (!str)
		return (NULL);
	index = 0;
	while (str[index] && str[index] == '0' && index < (int)ft_strlen(str) - 1)
	{
		index++;
	}
	new_str = ft_substr(str, index, ft_strlen(str) - index);
	free(str);
	if (new_str == NULL)
		return (NULL);
	return (new_str);
}
