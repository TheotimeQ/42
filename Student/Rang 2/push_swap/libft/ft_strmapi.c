/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:21:58 by tquere            #+#    #+#             */
/*   Updated: 2022/11/25 08:20:54 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	char	*str;

	if (!s || !f)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	index = 0;
	while (s[index])
	{
		str[index] = (*f)(index, s[index]);
		index++;
	}
	str[index] = '\0';
	return (str);
}
