/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:09:56 by tquere            #+#    #+#             */
/*   Updated: 2022/11/19 20:29:53 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
