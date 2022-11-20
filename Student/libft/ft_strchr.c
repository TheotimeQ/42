/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:08:53 by tquere            #+#    #+#             */
/*   Updated: 2022/11/19 20:29:53 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{	
	char	*str;
	int		index_str;
	char	c_char;

	c_char = c;
	str = (char *)s;
	index_str = 0;
	while (str[index_str] != c_char)
	{
		if (str[index_str] == '\0')
			return (NULL);
		index_str++;
	}
	return (&str[index_str]);
}
