/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:39:10 by tquere            #+#    #+#             */
/*   Updated: 2022/11/27 16:48:38 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{	
	int		index_str;
	char	*ptr;
	char	c_char;

	c_char = c;
	ptr = NULL;
	index_str = 0;
	while (s[index_str])
	{
		if (s[index_str] == c_char)
			ptr = &((char *)s)[index_str];
		index_str++;
	}
	if (s[index_str] == c_char)
		ptr = &((char *)s)[index_str];
	return (ptr);
}
