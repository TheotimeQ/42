/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:34:37 by tquere            #+#    #+#             */
/*   Updated: 2022/11/09 15:58:46 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
