/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:03:17 by tquere            #+#    #+#             */
/*   Updated: 2022/11/22 09:03:18 by tquere           ###   ########.fr       */
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
