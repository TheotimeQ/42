/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:39:08 by tquere            #+#    #+#             */
/*   Updated: 2022/11/08 17:21:14 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		length_find;
	size_t		index_str;
	size_t		index_find;

	length_find = ft_strlen(needle);
	index_str = 0;
	index_find = 0;
	while (haystack[index_str] && index_find < length_find && index_str < len)
	{
		index_find = 0;
		while (haystack[index_str + index_find] == needle[index_find]
			&& needle[index_find])
			index_find++;
		index_str++;
	}
	if (!(needle[0]))
		return (((char *)haystack));
	if (index_find == length_find)
		return (&((char *)haystack)[index_str - 1]);
	return (0);
}
