/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:34:37 by tquere            #+#    #+#             */
/*   Updated: 2022/11/08 16:42:28 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/libft.h"

char	*ft_strchr(const char *s, int c)
{	
	int	index_str;

	index_str = 0;
	while (s[index_str])
	{
		if (s[index_str] == c)
			return (&((char *)s)[index_str]);
		index_str++;
	}
	if (s[index_str] == c)
		return (&((char *)s)[index_str]);
	return (NULL);
}
