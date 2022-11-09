/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:21:51 by tquere            #+#    #+#             */
/*   Updated: 2022/11/09 15:58:46 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	index;
	char			*str;

	str = malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	index = 0;
	while (s[index] && index < start)
	{
		index++;
	}
	while (s[index] && index - start < len)
	{
		str[index - start] = s[index];
		index++;
	}
	str[index - start] = '\0';
	return (str);
}
