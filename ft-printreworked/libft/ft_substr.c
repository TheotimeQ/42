/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:10:04 by tquere            #+#    #+#             */
/*   Updated: 2022/11/20 16:01:47 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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