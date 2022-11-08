/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:39:10 by tquere            #+#    #+#             */
/*   Updated: 2022/11/08 16:45:11 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/libft.h"

char	*ft_strrchr(const char *s, int c)
{	
	int		index_str;
	char	*ptr;

	ptr = NULL;
	index_str = 0;
	while (s[index_str])
	{
		if (s[index_str] == c)
			ptr = &((char *)s)[index_str];
		index_str++;
	}
	if (s[index_str] == c)
		ptr = &((char *)s)[index_str];
	return (ptr);
}
