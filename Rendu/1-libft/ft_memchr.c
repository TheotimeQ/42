/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:34:26 by tquere            #+#    #+#             */
/*   Updated: 2022/11/09 15:58:46 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		index_str;
	char		*str;

	str = (char *)s;
	index_str = 0;
	while (str[index_str] && index_str < n)
	{
		if (str[index_str] == c)
			return (&str[index_str]);
		index_str++;
	}
	if (str[index_str] == c)
		return (&str[index_str]);
	return (NULL);
}
